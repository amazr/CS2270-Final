#include <iostream>

struct Node {
    static const int alphabet_size = 26;
    Node *adjLetters[alphabet_size];            //This is actually meant to be a hash map of pointers.
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