#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int new_data) {
        Node* new_node = new Node(new_data);
        if (isEmpty()) {
            front = rear = new_node;
            printQueue();
            return;
        }
        rear->next = new_node;
        rear = new_node;
        printQueue();
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        printQueue();
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Current Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();

    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();

    return 0;
}