#include<iostream>
using namespace std;

class Node{
    private:
    int data;
    Node* next;
    public:
    Node(){
        data = 0;
        next = NULL;
    }

    int getData(){
        return data;
    }
    void setData(int data){
        this->data = data;
    }
    Node* getNext(){
        return next;
    }
    void setNext(Node* next){
        this->next = next;
    }

};
class LinkedQueue{
    private:
    Node * front;
    Node * rear;
    public:
    LinkedQueue(){
        front = rear = NULL;
    }
    bool isEmpty(){
        if(front == NULL){
            return true;
        }else{
            return false;
        }
    }

    void Enqueue(int data){
        Node *newNode = new Node();
        newNode->setData(data);
        newNode->setNext(NULL);
        if (front == NULL)
        {
            front = rear = newNode;
        }else{
            rear->setNext(newNode);
            rear = newNode;
        }
        
    }

    void Dequeue(){
        Node *temp= front;
        front = front->getNext();
        delete temp;
    }

    int getFront(){
        return front->getData();
    }

    void printQueue(){
        Node *temp = front;
        if (front == NULL)
        {
            cout<<"Queue is Empty";
        }else{
            while (temp != NULL)
            {
                cout<<temp->getData()<<" ";
                temp = temp->getNext();
            }
            cout<<endl;
        }
        

    }
};

int main(){
    LinkedQueue lst;
    lst.Enqueue(100);
    lst.printQueue();
    lst.Enqueue(200);
    lst.printQueue();
    lst.Enqueue(300);
    lst.printQueue();
    lst.Enqueue(400);
    lst.printQueue();

    cout<<"The front element is "<<lst.getFront()<<endl;
}