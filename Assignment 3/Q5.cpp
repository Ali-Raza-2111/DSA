#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cerr << "Stack underflow! Aborting." << endl;
            exit(1);
        }
        Node* temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int evaluatePostfix(const string& expression) {
    Stack s;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            s.push(stoi(token));
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (token[0]) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                default: cerr << "Invalid operator in expression!" << endl; exit(1);
            }
        }
    }
    return s.pop();
}

int main() {
    string exp;
    cout << "Enter a postfix expression (e.g., 5 3 + 8 *): ";
    getline(cin, exp);

    int result = evaluatePostfix(exp);
    cout << "Result of the expression is: " << result << endl;

    return 0;
}
