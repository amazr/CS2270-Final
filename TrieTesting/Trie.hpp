#include <iostream>

struct Node {
    Node *adjLetters[25] = {};
    bool isWord;
};

class Trie {
    public:
        Trie();
        ~Trie();
        int letterHasher(char letter);          //CAP letter ascii - 65 = index in adjacent array
        void addWord(std::string input);        //Add's a word to the trie, no duplicates
        bool findWord(std::string input);       //Searches for a word in the trie
    private:
        Node *root;
};