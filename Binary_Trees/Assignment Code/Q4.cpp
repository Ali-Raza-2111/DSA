
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

    int findMin() {
        Node* curr = root;
        while (curr && curr->left != nullptr)
            curr = curr->left;
        return curr->data;
    }

    int findMax() {
        Node* curr = root;
        while (curr && curr->right != nullptr)
            curr = curr->right;
        return curr->data;
    }

    int height(Node* root) {
    if (root == nullptr)
        return -1;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return 1 + max(leftH, rightH);
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

    cout << "Minimum value: " << tree.findMin() << endl;
    cout << "Maximum value: " << tree.findMax() << endl;

    return 0;
}
