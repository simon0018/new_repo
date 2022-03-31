#include <iostream>
#include "searcher.h"

int main() {
    std::string path;
    path = "../text.txt"; 
    // std::cin >> pathRaw;
    std::string target;
    target = "the";
    target = "the";
    Searcher searcher(path);
    auto allOccurances = searcher.allOccurances("the");
    std::cout << "Found " << target << " in the following positions:\n";
    for (auto i: allOccurances) {
        std::cout << i << ' ';
    }
}


