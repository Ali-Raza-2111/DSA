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
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

int precedence(char c) {
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> st;
    string postfix = "";

    for(char c : infix) {
        if(isalnum(c))
            postfix += c;
        else if(c == '(')
            st.push(c);
        else if(c == ')') {
            while(!st.empty() && st.top()!='(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

Node* buildTree(const string& postfix) {
    stack<Node*> st;
    for(char c : postfix) {
        if(!isOperator(c)) {
            st.push(new Node(c));
        } else {
            Node* r = st.top(); st.pop();
            Node* l = st.top(); st.pop();
            Node* n = new Node(c);
            n->left = l;
            n->right = r;
            st.push(n);
        }
    }
    return st.top();
}

void postorder(Node* root) {
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    string infix;
    cin >> infix;

    string postfix = infixToPostfix(infix);
    Node* root = buildTree(postfix);

    postorder(root);
    return 0;
}
