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

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    
    if (key < root->getData()) {
        root->setLeft(deleteNode(root->getLeft(), key));
    }
    else if (key > root->getData()) {
        root->setRight(deleteNode(root->getRight(), key));
    }
    else {
        
        if (root->getLeft() == nullptr && root->getRight() == nullptr) {
            delete root;
            return nullptr;
        }

        
        if (root->getLeft() == nullptr) {
            Node* temp = root->getRight();
            delete root;
            return temp;
        }
        else if (root->getRight() == nullptr) {
            Node* temp = root->getLeft();
            delete root;
            return temp;
        }

        
        Node* successor = root->getRight();
        while (successor->getLeft() != nullptr) {
            successor = successor->getLeft();
        }

        
        root->setData(successor->getData());

        
        root->setRight(deleteNode(root->getRight(), successor->getData()));
    }

    return root;
}


Node* FindMinimum(Node* tree) {
    if (tree == nullptr) return nullptr;

    Node* current = tree;
    while (current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    return current;
}

void levelordertraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->getData() << " ";

        if (current->getLeft() != nullptr)
            q.push(current->getLeft());

        if (current->getRight() != nullptr)
            q.push(current->getRight());
    }
}
int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    // Find minimum
    Node* minNode = FindMinimum(root);
    if (minNode != nullptr)
        cout << "Minimum value: " << minNode->getData() << endl;

    // Delete a value
    cout << "Deleting 3..." << endl;
    root = deleteNode(root, 3);

    // Show result after deletion
    cout << "Level order after deletion: ";
    levelOrder(root);
    cout << endl;

    return 0;

    return 0;
}
