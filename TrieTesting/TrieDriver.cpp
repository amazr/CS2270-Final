#include "Trie.hpp"
#include <iostream>

//https://raw.githubusercontent.com/sujithps/Dictionary/master/Oxford%20English%20Dictionary.txt

int main() {
    Trie trie;
    std::string dictionary = "../dictionary/OxfordDictionary.txt";
    bool worked = trie.createTrieFromFile(dictionary);

    if (!worked) {
        std::cout << "There was an error loading the dictionary file\n";
        return 0;
    }

    while(true) {
        std::string search;   
        std::cout << "\nLook for a word: ";
        std::cin >> search;
        if (!trie.findWord(search)) std::cout << "Not Found!\n";
        trie.createSuggestionList(search);
        trie.printSuggestionList();
    }

}