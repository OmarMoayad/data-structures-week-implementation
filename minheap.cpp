#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;

        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        while (index > 0 && heap[parent(index)] > heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void deleteMin() {
        if (heap.empty()) {
            cout << "Heap is empty." << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    int getMin() {
        if (!heap.empty())
            return heap[0];
        cout << "Heap is empty." << endl;
        return -1;
    }
    void display() {
        cout << "Min Heap: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MinHeap h;
    vector<int> values = { 10, 7, 11, 5, 4, 13 };

    for (int val : values) {
        h.insert(val);
        cout << "Inserted " << val << " into the min-heap: ";
        h.display();
    }

    cout << "Minimum element: " << h.getMin() << endl;
    h.deleteMin();
    cout << "After deleting min: ";
    h.display();

    return 0;
}