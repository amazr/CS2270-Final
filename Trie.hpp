#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <QFile>
#include <QString>
#include <QTextStream>

struct Node {
    Node *adjLetters[26] = {};
    bool terminalLetter = false;
    std::string definition;
};

class Trie {
    public:
        Trie();
        ~Trie();
        bool createTrieFromFile(std::string fileName);  //Creates a trie from a given dictionary file
        bool createTrieFromQtFile(QString filePath);                    //Creates a trie from a Qt QFile object
        int letterHasher(char letter);          //CAP letter ascii - 65 = index in adjacent array
        void addWord(std::string input, std::string definition);        //Add's a word to the trie, no duplicates
        std::string findWord(std::string input);       //Searches for a word in the trie
        bool isChildless(Node *temp);           //Checks if the given node has children. Returns false if it has children.
        void printSuggestionList();             //prints the current list of suggested words.
        void clearSuggestionList();             //Clears the list of suggested words.
        void createSuggestionList(std::string input);   //Creates a list of suggested words for an invalid entry.
        std::vector<std::string> suggestionList;        //A list for storing suggestions.
    private:
        Node *root;
        std::string currentSuggestion;
        std::string rootSuggestion; 
        unsigned int suggestionSetCrawler;
        bool wordJustAdded;
        void fillSuggestionList(Node *currNode);        //Takes a current node and creates a list of suggestions from a word. Called by createSuggestionList.
        unsigned int numberOfSuggestions;
};
