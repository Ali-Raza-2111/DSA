#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(Node* node, int key) {
        if (node == nullptr)
            return false;
        if (node->data == key)
            return true;
        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    bool search(int key) {
        return search(root, key);
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (tree.search(key))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
