#include <iostream>
using namespace std;

#define Queue_Size 5

class QueueArray {
private:
    int queue[Queue_Size];
    int front;
    int rear;

public:
    QueueArray() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == Queue_Size - 1);
    }

    void Enqueue(int data) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
        } else {
            if (front == -1) front = 0;  
            queue[++rear] = data;
            cout << "Inserted: " << data << endl;
        }
    }

    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        } else {
            cout << "Deleted: " << queue[front] << endl;
            if (front == rear) {
                front = rear = -1; 
            } else {
                front++;
            }
        }
    }

    void PrintQueue() {
        if (isEmpty()) {
            cout << "The queue is Empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    QueueArray q;
    int choice, value;

    while (true) {
        cout << "\n==== Queue Menu ====\n";
        cout << "1. Insert Element into Queue\n";
        cout << "2. Delete Element from Queue\n";
        cout << "3. Display the Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.Enqueue(value);
            break;
        case 2:
            q.Dequeue();
            break;
        case 3:
            q.PrintQueue();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please enter 1-4." << endl;
        }
    }
}
