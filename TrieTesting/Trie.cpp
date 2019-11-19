#include "Trie.hpp"

//Constructor: 
Trie::Trie() {
    root = NULL;
}

//Destructor: 
Trie::~Trie() {

}

//Returns an int 0 - 25, wether it is caps or not, of a char. Used to find the index in the adj hash map
int Trie::letterHasher(char letter) {
    int key = int(letter) - 65;
    return (key <= 25) ? key : key - 32;
}

//Basically iterate through the word, hash each char and check the nodes adj list. If it is non-null, traverse down to it
//If it is null, create a new node and add the pointer, then traverse down to it.
void Trie::addWord(std::string input) {
    Node *temp = root;
    for (int i = 0; i < input.size(); i++) {
        int key = letterHasher(input[i]);
        if (temp->adjLetters[key] != NULL) {

        }
    }
}

bool Trie::findWord(std::string input) {

}