#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

void printInorder(Node* node) {
    if (!node) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node* node) {
    if (!node) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

int main() {
    Node* firstNode = new Node(2);
    Node* secondNode = new Node(3);
    Node* thirdNode = new Node(4);
    Node* fourthNode = new Node(5);

    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;

    cout << "Inorder traversal: ";
    printInorder(firstNode);
    cout << "\nPreorder traversal: ";
    printPreorder(firstNode);
    cout << "\nPostorder traversal: ";
    printPostorder(firstNode);
    cout << endl;

    delete fourthNode;
    delete thirdNode;
    delete secondNode;
    delete firstNode;

    return 0;
}
