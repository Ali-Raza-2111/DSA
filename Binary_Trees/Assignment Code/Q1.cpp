#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    int getData() { return data; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }

    void setData(int val) { data = val; }
    void setLeft(Node* l) { left = l; }
    void setRight(Node* r) { right = r; }

    bool isLeaf() { return (left == nullptr && right == nullptr); }
};

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->getLeft());
    cout << root->getData() << " ";
    inorder(root->getRight());
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->getData() << " ";
    preorder(root->getLeft());
    preorder(root->getRight());
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->getLeft());
    postorder(root->getRight());
    cout << root->getData() << " ";
}

int main() {
    Node* root = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    root->setLeft(n2);
    root->setRight(n3);
    n2->setLeft(n4);
    n2->setRight(n5);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
