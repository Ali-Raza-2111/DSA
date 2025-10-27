#include <iostream>
#include <cmath>      
#include <cctype>     
using namespace std;

#define STACKSIZE 50  

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

int evaluatePostfix(string expression) {
    Stack s;  

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

       
        if (isdigit(ch)) {
            s.Push(ch);
        }
        
        else {
            int val2 = s.Top() - '0'; s.Pop();
            int val1 = s.Top() - '0'; s.Pop();

            int result;
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }

            
            s.Push(result + '0');
        }
    }

    
    return s.Top() - '0';
}


int main() {
    string postfix;
    cout << "Enter a postfix expression (e.g., 23*54*+9-): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result of postfix expression: " << result << endl;

    return 0;
}
