//#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

//namespace fs = std::filesystem;

/*
 * Searcher gets a path to a text file (referred to as a haystack) in its
 * constructor, reads and processes it in linear time using linear amount of
 * memory. Then for a string (referred to as a needle) it can answer whether
 * the needle occurs in the haystack as a substring in linear time relative
 * to the length of the needle. Additionally it can return start indices of all
 * ocurrences.
 * Note: The size of the alphabet is referred as a constant in this analysis.
 * Note: Support for getting context and other features may be added.
 */
class Searcher {
public:
    Searcher(std::string pathToHaystack) {
        std::ifstream file(pathToHaystack, std::ios::binary);
        std::istreambuf_iterator<char> inputIt(file), sentinel;
        std::string haystack;
        std::back_insert_iterator<std::string> haystackInsert(haystack);
        std::copy(inputIt, sentinel, haystackInsert);
    }
    bool occurs([[maybe_unused]] std::string needle) {
        return false;
    }
    std::vector<std::size_t> allOccurences([[maybe_unused]] std::string needle) {
    }
private:
    SuffixAutomaton automaton_;
};

