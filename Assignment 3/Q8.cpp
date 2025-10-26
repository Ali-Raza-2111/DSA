#include <iostream>

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
        if (isEmpty()) {
            cerr << "Stack underflow!" << endl;
            exit(1);
        }
        Node* temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            return -1; 
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack (top to bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

Stack sortStack(Stack& input) {
    Stack tmpStack;

    while (!input.isEmpty()) {
        int tmp = input.pop();

        while (!tmpStack.isEmpty() && tmpStack.peek() > tmp) {
            input.push(tmpStack.pop());
        }
        tmpStack.push(tmp);
    }

    return tmpStack;
}

int main() {
    Stack inputStack;
    inputStack.push(34);
    inputStack.push(3);
    inputStack.push(31);
    inputStack.push(98);
    inputStack.push(92);
    inputStack.push(23);

    cout << "Original Stack:" << endl;
    inputStack.display();

    Stack sortedStack = sortStack(inputStack);

    cout << "\nSorted Stack (smallest on top):" << endl;
    sortedStack.display();

    return 0;
}
