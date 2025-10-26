#include <iostream>
using namespace std;

// Node structure for linked list
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
        cout << value << " pushed onto the stack." << endl;
    }

   
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! No elements to pop." << endl;
            return;
        }
        Node* temp = top; 
        cout << top->data << " popped from the stack." << endl;
        top = top->next; 
        delete temp; 
    }

    
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements (top to bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    
};

// Main function
int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    st.pop();
    st.display();
    
    return 0;
}
