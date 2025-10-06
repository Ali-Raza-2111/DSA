#include <iostream>
using namespace std;

class Node{
private:
int data;
Node * next;
public:
int getData(){
    return data;
}  
Node *getNext(){
    return next;
}

void setData(int data){
    this->data = data;
}
void setNext(Node *next){
    this->next = next;
}
};

class List{
private:
    Node*head;
    Node *tail;
public:
List(){
    head = tail = NULL;
}

void print(){
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->getData()<<" ";
        temp = temp->getNext();
    }
    cout<<endl;
}

void insert(int val){
    Node *newNode = new Node();
    newNode->setData(val);
    newNode->setNext(NULL);
    if (head == NULL)
    {
        head= tail = newNode;
    }else{
        tail->setNext(newNode);
        tail = newNode;
    }
    
}

void deleteValue(int val){
    if (head == NULL)
    {
        return;
    }

    if (head->getData() == val)
    {
        Node *temp = head;
        head = temp->getNext();
        delete temp;
        if (head == NULL)
        {
            tail = NULL;   
        }
        return;
        
    }

    Node *current = head;
    while (current->getNext()!=NULL && current->getNext()->getData()!=val)
    {
        current = current->getNext();
    }

    if (current->getNext() == NULL)
    {
        return;
    }

    Node *temp = current->getNext();
    current->setNext(temp->getNext());

    if (temp->getNext() == NULL)
    {
        tail = current;
    }
    delete temp;
}

void addBetween(int val,int indx){
    Node * newNode = new Node();
    newNode->setData(val);
    newNode->setNext(NULL);
    int i = 0;
    Node *temp = head;
    while (i<indx)
    {
        temp = temp->getNext();
        i++;
    }
    newNode->setNext(temp->getNext());
    temp->setNext(newNode);
    
}

void deleteAtPos(int pos){
    if (pos == 1)
    {
        Node*temp = head;
        head = temp->getNext();
        delete temp;
    }else{
        Node *current = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt<=pos)
        {
            prev = current;
            current = current->getNext();
        }
        
        
    }
    
}
};
int main() {
    List ll;

    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.print();
    ll.addBetween(6,0);
    ll.print();
    return 0;
}
