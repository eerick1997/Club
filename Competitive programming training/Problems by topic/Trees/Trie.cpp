#include <bits/stdc++.h>

using namespace std;

struct Trie {
    struct Node {
        unordered_map<char, Node*> letters;
        bool isEndWord;
        Node() {
            isEndWord = false;
        }
    };

    Node *root;

    Trie() {
        root = new Node();
    }

    bool exists(Node *current, const char c) {
        return current -> letters.find(c) != current -> letters.end();
    }

    void insertWord(const string &word) {
        Node *current = root;
        for(auto &c : word) {
            if(!exists(current, c))
                current -> letters[c] = new Node();
            current = current -> letters[c];
        }
        current -> isEndWord = true;
    }

    bool findWord(const string &word) {
        Node *current = root;
        for(auto &c : word) {
            if(!exists(current, c))
                return false;
            current = current -> letters[c];
        }
        return current -> isEndWord;
    }
};

/**
                O
            /       \
            g        p
            |        |
            a        l
            |        |
            t        a
          /  \       |
         o*  a*      t
        |          /   \
        s*        o*   a*
**/
int main() {

    Trie *trie = new Trie();
    bool isInTree;
    trie -> insertWord("gato");
    trie -> insertWord("gata");
    trie -> insertWord("gatos");
    trie -> insertWord("plato");
    trie -> insertWord("plata");
    isInTree = trie -> findWord("gato");
    cout << "gato exists? = " << (isInTree ? "Yes" : "No") << endl;
    isInTree = trie -> findWord("plata");
    cout << "plata exists? = " << (isInTree ? "Yes" : "No") << endl;
    isInTree = trie -> findWord("gatas");
    cout << "gatas exists? = " << (isInTree ? "Yes" : "No") << endl;

    return 0;
}