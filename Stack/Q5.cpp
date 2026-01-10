#include <iostream>
using namespace std;

#define STACKSIZE 100 


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
            return '\0';  
    }
};


bool isMatchingPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}




bool areSymbolsBalanced(const string& expr) {
    Stack s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        
        if (ch == '(' || ch == '{' || ch == '[') {
            s.Push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false; 
            } else if (!isMatchingPair(s.Top(), ch)) {
                return false; 
            } else {
                s.Pop();
            }
        }
    }

    
    return s.isEmpty();
}


int main() {
    string expression;
    cout << "Enter an expression with symbols: ";
    cin >> expression;

    if (areSymbolsBalanced(expression))
        cout << "Symbols are balanced!" << endl;
    else
        cout << "Symbols are NOT balanced!" << endl;

    return 0;
}
