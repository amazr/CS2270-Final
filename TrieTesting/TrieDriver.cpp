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
    std::cout << "adding words...\n";
    while(getline(ifs, line)) {
        trie.addWord(line);
    }
    while(true) {
        std::string search;   
        std::cout << "done!\nLook for a word: \n";
        std::cin >> search;
        if (search == "123") return 0;
        if (trie.findWord(search)) std::cout << "FOUND!\n";
        else std::cout << "NOT FOUND!\n";
    }
}