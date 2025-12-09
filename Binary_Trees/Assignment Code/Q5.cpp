#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

Node* buildExpressionTree(const string& postfix) {
    stack<Node*> st;
    for (char c : postfix) {
        if (!isOperator(c)) {
            st.push(new Node(c));
        } else {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            Node* newNode = new Node(c);
            newNode->left = left;
            newNode->right = right;
            st.push(newNode);
        }
    }
    return st.top();
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    string postfix;
    cin >> postfix;

    Node* root = buildExpressionTree(postfix);
    inorder(root);
    return 0;
}
