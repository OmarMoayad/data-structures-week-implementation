#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
Node* insertAtPosition(Node* last, int data, int pos) {
    if (last == nullptr) {
        if (pos != 1) {
            cout << "Invalid position!" << endl;
            return last;
        }

        Node* newNode = new Node(data);
        last = newNode;
        last->next = last;
        return last;
    }

    Node* newNode = new Node(data);

    Node* curr = last->next;

    if (pos == 1) {
        newNode->next = curr;
        last->next = newNode;
        return last;
    }

    for (int i = 1; i < pos - 1; ++i) {
        curr = curr->next;

        if (curr == last->next) {
            cout << "Invalid position!" << endl;
            return last;
        }
    }
    newNode->next = curr->next;
    curr->next = newNode;

    if (curr == last) last = newNode;

    return last;
}

void printList(Node* last) {
    if (last == NULL) return;

    Node* head = last->next;
    while (true) {
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) break;
    }
    cout << endl;
}

int main() {

   
    Node* first = new Node(1);
    first->next = new Node(2);
    first->next->next = new Node(3);

    Node* last = first->next->next;
    last->next = first;

    cout << "Original list: ";
    printList(last);
    int data = 4, pos = 2;
    last = insertAtPosition(last, data, pos);
    cout << "List after insertions: ";
    printList(last);

    return 0;
}