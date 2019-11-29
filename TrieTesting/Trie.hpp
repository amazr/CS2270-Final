#include <iostream>
#include <vector>

struct Node {
    Node *adjLetters[26] = {};
    bool terminalLetter = false;
};

class Trie {
    public:
        Trie();
        ~Trie();
        int letterHasher(char letter);          //CAP letter ascii - 65 = index in adjacent array
        void addWord(std::string input);        //Add's a word to the trie, no duplicates
        bool findWord(std::string input);       //Searches for a word in the trie
        bool isChildless(Node *temp);           //Checks if the given node has children. Returns false if it has children.
        void printSuggestionList();             //prints the current list of suggested words.
        void clearSuggestionList();             //Clears the list of suggested words.
        void createSuggestionList(std::string input);   //Creates a list of suggested words for an invalid entry.      
    private:
        Node *root;
        std::vector<std::string> suggestionList;
        std::string currentSuggestion;
        std::string rootSuggestion; 
        int suggestionSetCrawler;
        int stackLevel;
        bool wordJustAdded;
        void fillSuggestionList(Node *currNode);        //Takes a current node and creates a list of suggestions from a word. Called by createSuggestionList.
};