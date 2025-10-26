#include <iostream>

using namespace std;

struct QNode {
    int data;
    QNode* next;
    QNode(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
public:
    QNode *front, *rear;
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int x) {
        QNode* temp = new QNode(x);
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    int dequeue() {
        if (front == nullptr) {
            return -1;
        }
        QNode* temp = front;
        int val = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return val;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int getSize() {
        int count = 0;
        QNode* temp = front;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class Stack {
    Queue q1, q2;

public:
    void push(int x) {
        q1.enqueue(x);
        cout << "Pushed " << x << " onto stack." << endl;
    }

    int pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }

        while (q1.getSize() > 1) {
            q2.enqueue(q1.dequeue());
        }

        int popped_value = q1.dequeue();

        Queue temp_q = q1;
        q1 = q2;
        q2 = temp_q;

        return popped_value;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "\nPopped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    s.push(40);

    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    return 0;
}
