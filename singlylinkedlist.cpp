#include <iostream>
using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;
    int length;

public:
    SinglyLinkedList() : head(nullptr), length(0) {}

    ~SinglyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void add(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next)
                current = current->next;
            current->next = newNode;
        }
        length++;
    }

    int get(int index) {
        if (index < 0 || index >= length) {
            cout << "Error: index out of bounds" << endl;
            return -1;
        }
        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        return current->data;
    }

    void set(int index, int value) {
        if (index < 0 || index >= length) {
            cout << "Error: index out of bounds" << endl;
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        current->data = value;
    }

    void removeAt(int index) {
        if (index < 0 || index >= length) {
            cout << "Error: index out of bounds" << endl;
            return;
        }

        Node* toDelete = nullptr;
        if (index == 0) {
            toDelete = head;
            head = head->next;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i)
                current = current->next;
            toDelete = current->next;
            current->next = current->next->next;
        }
        delete toDelete;
        length--;
    }

    int size() const {
        return length;
    }

    void print() const {
        Node* current = head;
        cout << "[";
        while (current) {
            cout << current->data;
            if (current->next)
                cout << ", ";
            current = current->next;
        }
        cout << "]" << endl;
    }
};

int main() {
    SinglyLinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.print(); // [10, 20, 30]

    cout << "Element at index 1: " << list.get(1) << endl; // 20

    list.set(1, 99);
    list.print(); // [10, 99, 30]

    list.removeAt(0);
    list.print(); // [99, 30]

    cout << "Size: " << list.size() << endl; // 2

    return 0;
}
