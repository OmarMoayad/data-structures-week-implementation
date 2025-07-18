#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf;

    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

    bool deleteHelper(TrieNode* node, const string& key, int depth) {
        if (!node) return false;

        if (depth == (int)key.size()) {
            if (!node->isLeaf) return false;

            node->isLeaf = false;

            for (int i = 0; i < 26; i++)
                if (node->children[i]) return false;

            return true;
        }

        int index = key[depth] - 'a';
        if (deleteHelper(node->children[index], key, depth + 1)) {
            delete node->children[index];
            node->children[index] = nullptr;

            if (!node->isLeaf) {
                for (int i = 0; i < 26; i++)
                    if (node->children[i]) return false;
                return true;
            }
        }
        return false;
    }

    void dfsHelper(TrieNode* node, string& currentWord) {
        if (!node) return;

        if (node->isLeaf)
            cout << currentWord << "\n";

        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                currentWord.push_back('a' + i);
                dfsHelper(node->children[i], currentWord);
                currentWord.pop_back();
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& key) {
        TrieNode* node = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isLeaf = true;
    }

    bool search(const string& key) const {
        TrieNode* node = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node != nullptr && node->isLeaf;
    }

    void remove(const string& key) {
        deleteHelper(root, key, 0);
    }

    // BFS without std::queue: manual circular queue
    void bfs() const {
        const int MAX = 1000;
        struct NodeChar {
            TrieNode* node;
            char ch;
        };

        NodeChar queue[MAX];
        int front = 0, rear = 0;

        // Enqueue root with dummy char '-'
        queue[rear++] = {root, '-'};

        while (front != rear) {
            NodeChar nc = queue[front++];
            if (front == MAX) front = 0; // circular wrap

            if (nc.ch != '-')
                cout << nc.ch << ' ';

            for (int i = 0; i < 26; i++) {
                if (nc.node->children[i]) {
                    queue[rear++] = {nc.node->children[i], (char)('a' + i)};
                    if (rear == MAX) rear = 0; // circular wrap
                }
            }
        }
        cout << "\n";
    }

    void dfsPrintAllWords() {
        string currentWord;
        dfsHelper(root, currentWord);
    }
};

int main() {
    Trie trie;

    trie.insert("hello");
    trie.insert("hell");
    trie.insert("help");
    trie.insert("helium");

    cout << boolalpha;
    cout << "Search 'hell': " << trie.search("hell") << "\n";
    cout << "Search 'hello': " << trie.search("hello") << "\n";
    cout << "Search 'help': " << trie.search("help") << "\n";
    cout << "Search 'helium': " << trie.search("helium") << "\n";
    cout << "Search 'hero': " << trie.search("hero") << "\n";

    cout << "\nBFS traversal (characters):\n";
    trie.bfs();

    cout << "\nDFS traversal (all words):\n";
    trie.dfsPrintAllWords();

    trie.remove("hell");
    cout << "\nAfter removing 'hell':\n";
    cout << "Search 'hell': " << trie.search("hell") << "\n";
    cout << "Search 'hello': " << trie.search("hello") << "\n";

    return 0;
}
