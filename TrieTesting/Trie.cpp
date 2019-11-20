#include "Trie.hpp"

void destroy(Node *node) {
    //Recur down trie the entire way
    for(int i = 0; i < 26; i += 1) {
        if(node->adjLetters[i] != NULL)
            destroy(node->adjLetters[i]);
    }
    //Delete nodes as the stack clears
    delete node;
}

//Constructor: 
Trie::Trie() {
    root = new Node();
}

//Destructor: 
Trie::~Trie() {
    destroy(root);
}

//Returns an int 0 - 25, wether it is caps or not, of a char. Used to find the index in the adj hash map
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
    return true;
}