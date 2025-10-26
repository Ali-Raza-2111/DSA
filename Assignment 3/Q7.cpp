#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        Node* temp = top;
        char value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool areParenthesesBalanced(string expr) {
    Stack s;
    char popped_char;

    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
            continue;
        }

        if (c == ')' || c == ']' || c == '}'){
            if (s.isEmpty()) {
               return false;
            }
            popped_char = s.pop();
            if (c == ')' && popped_char != '(') {
                return false;
            }
            if (c == ']' && popped_char != '[') {
                return false;
            }
            if (c == '}' && popped_char != '{') {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string expression;
    cout << "Enter an expression to check for balanced parentheses: ";
    getline(cin, expression);

    if (areParenthesesBalanced(expression)) {
        cout << "The expression has balanced parentheses." << endl;
    } else {
        cout << "The expression does not have balanced parentheses." << endl;
    }

    return 0;
}
