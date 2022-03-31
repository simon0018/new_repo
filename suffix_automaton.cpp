#include <vector>
#include <string>
#include <map>
using namespace std;




//template<class String, class Symbol = typename String::value_type>




struct State {
    State(int len_, int link_)
            : len(len_)
            , link(link_)
    {}

    int len, link;
    std::map<char, int> next;
    bool isClone;
    int firstPosition;
    std::vector<int> inverseLink;
};

class Automaton {
public:
    Automaton(const std::string& haystack) {
        init_();
        for (char i: haystack) {
            extend_(i);
        }
        for (size_t v = 1; v < tree.size(); ++v) {
            tree[tree[v].link].inverseLink.push_back(v);
        }
    }
    int getNode(const std::string& substring) {
        int v = 0;
        for (char x: substring) {
            if (tree[v].next.count(x) == 0) {
                v = -1;
                break;
            }
            v = tree[v].next[x];
        }
        return v;
    }
    int 
private:
    std::vector<State> tree;
    int last;

    void getOccurrences_(int v, int ofLength, std::vector<int>& result) {
        if (!tree[v].isClone)
            result.push_back(tree[v].firstPosition - P_length + 1);
        for (int u: tree[v].inverseLink)
            getOccurrences_(u, length, result);
        return result;
    }

    void init_() {
        tree.emplace_back(0, -1);
        last = 0;
    }

    void extend_(char c) {
        int cur = tree.size();
        tree.emplace_back();
        tree[cur].len = tree[last].len + 1;
        tree[cur].firstPosition = tree[cur].len - 1; ////
        int p = last;
        while (p != -1 && !tree[p].next.count(c)) {
            tree[p].next[c] = cur;
            p = tree[p].link;
        }
        if (p == -1) {
            tree[cur].link = 0;
        } else {
            int q = tree[p].next[c];
            if (tree[p].len + 1 == tree[q].len) {
                tree[cur].link = q;
            } else {
                int clone = tree.size();
                tree.emplace_back();
                tree[clone].len = tree[p].len + 1;
                tree[clone].next = tree[q].next;
                tree[clone].link = tree[q].link;
                tree[clone].isClone = true; ///////
                tree[clone].firstPosition = tree[q].firstPosition; /////
                while (p != -1 && tree[p].next[c] == q) {
                    tree[p].next[c] = clone;
                    p = tree[p].link;
                }
                tree[q].link = tree[cur].link = clone;
            }
        }
        last = cur;
    }

    // output all positions of occurrences
    void output_all_occurrences(int v, int P_length) {
        if (!tree[v].isClone)
            std::cout << tree[v].firstPosition - P_length + 1 << std::endl;
        for (int u : tree[v].inverseLink)
            output_all_occurrences(u, P_length);
    }
}

