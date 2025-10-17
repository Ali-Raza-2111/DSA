#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;


    public:
    int getData(){
        return data;
    }

    void setDate(int data)
    {
        this->data = data;
    }

    Node *getNext(){
        return next;
    }

    void setNext(Node *next){
        this->next = next;
    }

    Node * getPrev(){
        return prev;
    }

    void setPrev(Node * prev){
        this->prev = prev;
    }

};

class list{
    public:
    Node *head;
    Node *tail;

    list(){
        head = tail = NULL;
    }
    void insert(int data){
        Node *newNode = new Node();
        newNode->setDate(data);
        newNode->setNext(NULL);
        newNode->setPrev(NULL);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
        
        
    }
    
    void printLL(){
        Node *temp = head;
        while (temp !=NULL)
        {
            cout<<temp->getData()<<" ";
            temp = temp->getNext();
        }
        
    }

    void printBack(){
        Node *temp = tail;
        while (temp!=NULL)
        {
            cout<<temp->getData()<<" ";
            temp = temp->getPrev();
        }
        
    }

    void deleteNode(int n){
        // case 1
        if (head->getData() == n)
        {
            Node *temp = head;
            head = temp->getNext();
            delete temp;
            return;
        }
        if(tail->getData()==n){
            Node* temp=tail;
            tail=temp->getPrev();
            tail->setNext(NULL);
            delete temp;
            return;
        }
        Node *temp = head;
        while (temp->getData() != n)
        {
            temp = temp->getNext();
        }
        // temp->getPrev()->setNext(temp->getNext());
        // delete temp;
        Node *prev = temp->getPrev();
        Node * next2 = temp->getNext();
        prev->setNext(next2);
        next2->setPrev(prev);
        delete temp;
        
        
    }

};
int main(){
    list ll;
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.printLL();
    ll.deleteNode(3);
    ll.deleteNode(4);
    cout<<endl;
    ll.printLL();
    // ll.printBack();
    return 0;
}