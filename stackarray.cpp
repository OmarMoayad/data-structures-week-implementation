#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int topIndex;

    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        for (int i = 0; i <= topIndex; ++i)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    Stack() {
        capacity = 4;
        arr = new int[capacity];
        topIndex = -1; // فارغ بالبداية
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (topIndex + 1 == capacity)
            resize();
        arr[++topIndex] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop.\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }

    void print() {
        cout << "Stack (top -> bottom): ";
        for (int i = topIndex; i >= 0; --i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.print(); // Stack (top -> bottom): 30 20 10

    cout << "Top: " << s.top() << endl; // 30

    s.pop();
    s.print(); // Stack (top -> bottom): 20 10

    cout << "Size: " << s.size() << endl; // 2
    cout << (s.isEmpty() ? "Empty" : "Not empty") << endl;

    return 0;
}
