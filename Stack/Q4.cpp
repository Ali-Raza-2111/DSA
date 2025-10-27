#include <iostream>
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

void decimalToBinary(int decimalNumber) {
    Stack s;
    
    if (decimalNumber == 0) {
        cout << "Binary: 0" << endl;
        return;
    }

   
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 2;
        s.Push(remainder + '0');
        decimalNumber = decimalNumber / 2;
    }

    
    cout << "Binary: ";
    while (!s.isEmpty()) {
        cout << s.Top();
        s.Pop();
    }
    cout << endl;
}


int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;

    decimalToBinary(number);

    return 0;
}
