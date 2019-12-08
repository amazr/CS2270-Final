#include "Trie.hpp"


//Start of helper functions

void destroy(Node *node) {
    //Recur down trie the entire way
    for(int i = 0; i < 26; i += 1) {
        if(node->adjLetters[i] != nullptr)
            destroy(node->adjLetters[i]);
    }
    //Delete nodes as the stack clears
    delete node;
}

char intToChar(int key) {
    return (char)('A' + key);
}

//Constructor:  ALSO start of Trie functions
Trie::Trie() {
    root = new Node();
    numberOfSuggestions = 5;
}

//Destructor: 
Trie::~Trie() {
    destroy(root);
}

bool Trie::createTrieFromQtFile(QString filePath) {
    QFile inputFile(filePath);
    QString word = "";
    QString definition = "";
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if (line.size() == 0) continue;

          word = line.section("  ",0,0);
          definition = line.section("  ",1,1);

          if (word.size() == 0) continue;
          addWord(word.toStdString(), definition.toStdString());
       }
       inputFile.close();
    }
    return true;
}

bool Trie::createTrieFromFile(std::string fileName) {
    std::ifstream ifs;
    ifs.open(fileName);
    
    if (!ifs.is_open()) return false;

    std::string line;
    std::string word;
    std::string definition;
    while(getline(ifs, line)) {
        if (line.size() == 0) continue;
        line.erase(line.length() - 1);
        for (unsigned int i = 0; i < line.size(); i++) {
            if (i >= 1) {
                if (line[i] == ' ' && line[i - 1] == ' ') {
                    definition = line.substr(i + 1, line.size() + 1);
                    break;
                }
            }
            word += line[i];
        }
        if (word.size() == 0) continue;
        word.erase(word.length()-1);
        addWord(word,definition);
        word = "";
        definition = "";
    }  
    return true;
}

//Returns an int 0 - 25, wether it is caps or not, of a char. Used to find the index in the adj hash map
//WARNING: If passed a non-letter, letterHasher will return a value outside 0-25, which can cause a seg fault
int Trie::letterHasher(char letter) {
    int key = int(letter) - 65;
    return (key <= 25) ? key : key - 32;
}

//Adds a word to the trie
void Trie::addWord(std::string input, std::string definition) {
    Node *temp = root;
    int key = 0;
    for (unsigned int i = 0; i < input.size(); i++) {
        key = letterHasher(input[i]);
        if (key < 0 || key > 25) continue;
        if (temp->adjLetters[key] == nullptr) {
            temp->adjLetters[key] = new Node();
        }
        temp = temp->adjLetters[key];
    }
    temp->terminalLetter = true;
    temp->definition = definition;
}

//Returns true if a given word is in the tree, false if it was not
std::string Trie::findWord(std::string input) {
    Node *temp = root;
    int key = 0;
    for (unsigned int i = 0; i < input.size(); i++) {

        key = letterHasher(input[i]);
        if (key < 0 || key > 25) return "-1";
        if (temp->adjLetters[key] == nullptr) return "-1";

        temp = temp->adjLetters[key];
    }
    if (temp->terminalLetter) return temp->definition;
    return "-1";
}

//Checks if the node has no children
bool Trie::isChildless(Node *temp) {
    for (unsigned int i = 0; i < 26; i++) {
        if (temp->adjLetters[i] != nullptr) return false;
    }
    return true;
}

//Prints the current list of suggested words
void Trie::printSuggestionList() {
    for (unsigned int i = 0; i < suggestionList.size(); i++) {
        std::cout << suggestionList.at(i) << "\n";
    }
}

//Clears the suggestion list
void Trie::clearSuggestionList() {
    suggestionList.clear();
}

//Creates a list of suggested words, just the first 5 words alphabetically 
void Trie::createSuggestionList(std::string input) {
    clearSuggestionList();
    rootSuggestion = "";
    Node *temp = root;
    char currentLetter;
    for (unsigned int i = 0; i < input.size(); i++) {

        int key = letterHasher(input[i]);
        if (key < 0 || key > 25) continue;

        if (temp->adjLetters[key] != nullptr) {
            currentLetter = intToChar(key);
            rootSuggestion += currentLetter;
            temp = temp->adjLetters[key];
            continue;
        }
        break;
    }

    suggestionSetCrawler = 0;
    currentSuggestion = rootSuggestion;
    fillSuggestionList(temp);
}

//This recursive functions works by filling a vector with words as it traverses the entire trie. It will stop at a predetermined number of words. 
void Trie::fillSuggestionList(Node *temp) {
    
    if (temp->terminalLetter == true && suggestionList.size() <= (numberOfSuggestions - 1) && currentSuggestion != rootSuggestion) {
        suggestionSetCrawler++;
        suggestionList.push_back(currentSuggestion);
    }

    for (unsigned int i = 0; i < 26; i++) {
        if (suggestionList.size() > (numberOfSuggestions - 1)) return;
        if (temp->adjLetters[i] != nullptr) {
            currentSuggestion += intToChar(i);
            fillSuggestionList(temp->adjLetters[i]);
        }
    }
    currentSuggestion.pop_back();
}



