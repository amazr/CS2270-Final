#include "Trie.hpp"

//Start of helper functions

void destroy(Node *node) {
    //Recur down trie the entire way
    for(int i = 0; i < 26; i += 1) {
        if(node->adjLetters[i] != NULL)
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
    numberOfSuggestions = 10;
}

//Destructor: 
Trie::~Trie() {
    destroy(root);
}

//Returns an int 0 - 25, wether it is caps or not, of a char. Used to find the index in the adj hash map
//WARNING: If passed a non-letter, letterHasher will return a value outside 0-25, which can cause a seg fault
int Trie::letterHasher(char letter) {
    int key = int(letter) - 65; 
    return (key <= 25) ? key : key - 32;
}

//Adds a word to the trie
void Trie::addWord(std::string input) {
    Node *temp = root;
    int key = 0;
    int size = input.size();
    for (int i = 0; i < size; i++) {
        key = letterHasher(input[i]);
        if (key < 0 || key > 25) continue;
        if (temp->adjLetters[key] == NULL) {
            temp->adjLetters[key] = new Node();
        }
        temp = temp->adjLetters[key];
    }
    temp->terminalLetter = true;
}

//Returns true if a given word is in the tree, false if it was not
bool Trie::findWord(std::string input) {
    Node *temp = root;
    int key = 0;
    int size = input.size();
    for (int i = 0; i < size; i++) {

        key = letterHasher(input[i]);
        if (key < 0 || key > 25) return false;
        if (temp->adjLetters[key] == NULL) return false;

        temp = temp->adjLetters[key];
    }
    if (temp->terminalLetter) return true;
    return false;
}

//Checks if the node has no children
bool Trie::isChildless(Node *temp) {
    for (int i = 0; i < 26; i++) {
        if (temp->adjLetters[i] != NULL) return false;
    }
    return true;
}

//Prints the current list of suggested words
void Trie::printSuggestionList() {
    for (int i = 0; i < suggestionList.size(); i++) {
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
    for (int i = 0; i < input.size(); i++) {

        int key = letterHasher(input[i]);
        if (key < 0 || key > 25) continue;

        if (temp->adjLetters[key] != NULL) {
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

//Make this just return all the way when a word is found, and loop through calling this in the parent function!
void Trie::fillSuggestionList(Node *temp) {
    
    if (temp->terminalLetter == true && suggestionList.size() <= (numberOfSuggestions - 1) && currentSuggestion != rootSuggestion) {
        suggestionSetCrawler++;
        suggestionList.push_back(currentSuggestion);
    }

    for (int i = 0; i < 26; i++) {
        if (suggestionList.size() > (numberOfSuggestions - 1)) return;
        if (temp->adjLetters[i] != NULL) {
            currentSuggestion += intToChar(i);
            fillSuggestionList(temp->adjLetters[i]);
        }
    }
    currentSuggestion.pop_back();
}



