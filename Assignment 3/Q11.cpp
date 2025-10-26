#include <iostream>

using namespace std;

struct SNode {
    int data;
    SNode* next;
};

class Stack {
private:
    SNode* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        SNode* newNode = new SNode();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        SNode* temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

class Queue {
    Stack s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
        cout << "Enqueued " << x << endl;
    }

    int dequeue() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }

        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        int val = s2.pop();
        return val;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "\nDequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(40);
    q.enqueue(50);

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}
