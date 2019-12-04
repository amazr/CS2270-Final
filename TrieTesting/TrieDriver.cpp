#include "Trie.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


int main() {
    Trie trie;
    std::string dictionary = "../dictionary/words_alpha.txt";
    
    std::ifstream ifs;
    ifs.open(dictionary);

    if (!ifs.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 0;
    }

    std::string line;
    std::cout << "adding words...";
    while(getline(ifs, line)) {
        line.erase(line.length() - 1);  //This erases a carriage return... keep checking if this is needed once the file changes
        trie.addWord(line);
    }
    std::cout << " DONE\n";
    while(true) {
        std::string search;   
        std::cout << "\nLook for a word: ";
        std::cin >> search;
        if (trie.findWord(search)) std::cout << "FOUND!\n";
        else std::cout << "NOT FOUND\n";
        trie.createSuggestionList(search);
        trie.printSuggestionList();
    }

}