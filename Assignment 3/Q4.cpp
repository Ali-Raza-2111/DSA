#include <iostream>
#include <cctype>   // for isalnum()
using namespace std;

const int STACKSIZE = 100;  // increased size for expressions

class Stack {
private:
    char stackArray[STACKSIZE];
    int TOP;

public:
    Stack() {
        TOP = -1;
    }

    bool isEmpty() {
        return (TOP == -1);
    }

    bool isFull() {
        return (TOP == STACKSIZE - 1);
    }

    void Push(char element) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << element << endl;
        } else {
            TOP++;
            stackArray[TOP] = element;
        }
    }

    void Pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
        } else {
            TOP--;
        }
    }

    char Top() {
        if (!isEmpty())
            return stackArray[TOP];
        else
            return '\0';  // return null if empty
    }
};

// Function to define precedence
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix using your Stack
string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;  // operand → directly to output
        } else if (c == '(') {
            st.Push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.Top() != '(') {
                postfix += st.Top();
                st.Pop();
            }
            st.Pop(); // remove '('
        } else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.Top()) >= precedence(c)) {
                postfix += st.Top();
                st.Pop();
            }
            st.Push(c);
        }
    }

    // Pop remaining operators
    while (!st.isEmpty()) {
        postfix += st.Top();
        st.Pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}
