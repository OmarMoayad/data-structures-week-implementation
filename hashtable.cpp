#include <vector>
#include <iostream>
using namespace std;

class HashTable {
private:
    int BUCKET;
    vector<vector<int>> table;

    int hashFunction(int x) {
        return (x % BUCKET);
    }

public:
    HashTable(int b) {
        BUCKET = b;
        table.resize(BUCKET);
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);

        for (size_t i = 0; i < table[index].size(); ++i) {
            if (table[index][i] == key) {
                table[index].erase(table[index].begin() + i);
                break;
            }
        }
    }

    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i;
            for (int x : table[i]) {
                cout << " --> " << x;
            }
            cout << endl;
        }
    }
};

int main() {
    vector<int> a = { 15, 11, 27, 8, 12 , 13, 10, 33, 22 , 8 };

    HashTable h(10);
    for (int key : a)
        h.insertItem(key);

    h.deleteItem(12);
    h.displayHash();

    return 0;
}
