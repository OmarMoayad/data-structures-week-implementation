#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* topNode; // رأس الستاك (أعلى عنصر)
    int count;     // عدد العناصر

public:
    Stack() : topNode(nullptr), count(0) {}

    ~Stack() {
        while (!isEmpty())
            pop();
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop.\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int size() {
        return count;
    }

    void print() {
        cout << "Stack (top -> bottom): ";
        Node* current = topNode;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(100);
    s.push(200);
    s.push(300);

    s.print(); // Stack (top -> bottom): 300 200 100

    cout << "Top: " << s.top() << endl; // 300

    s.pop();
    s.print(); // Stack (top -> bottom): 200 100

    cout << "Size: " << s.size() << endl; // 2

    cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;

    return 0;
}
