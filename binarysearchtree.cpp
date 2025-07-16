#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

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
    Node* root = nullptr;

    // Insert nodes to keep BST property
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 13);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 1);

    cout << "Inorder traversal: ";
    printInorder(root);
    cout << "\nPreorder traversal: ";
    printPreorder(root);
    cout << "\nPostorder traversal: ";
    printPostorder(root);
    cout << endl;



    return 0;
}