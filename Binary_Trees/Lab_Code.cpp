#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

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

static int idx = -1;


Node* buildTree(vector<int> preorder) {
    idx++;
    if (preorder[idx] == -1) return nullptr;

    Node* root = new Node(preorder[idx]);
    root->setLeft(buildTree(preorder));
    root->setRight(buildTree(preorder));
    return root;
}


void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->getData() << " ";
    preOrder(root->getLeft());
    preOrder(root->getRight());
}


void inOrderTraversal(Node* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->getLeft());
    cout << root->getData() << " ";
    inOrderTraversal(root->getRight());
}


void postOrderTraversal(Node* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->getLeft());
    postOrderTraversal(root->getRight());
    cout << root->getData() << " ";
}


void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->getData() << " ";
        if (temp->getLeft() != nullptr) q.push(temp->getLeft());
        if (temp->getRight() != nullptr) q.push(temp->getRight());
    }
}


Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);

    if (val < root->getData()) {
        root->setLeft(insert(root->getLeft(), val));
    } else if (val > root->getData()) {
        root->setRight(insert(root->getRight(), val));
    }

    return root;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    cout << "Level order before insert: ";
    levelOrder(root);
    cout << endl;

    root = insert(root, 6);  
    cout << "Level order after insert: ";
    levelOrder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
