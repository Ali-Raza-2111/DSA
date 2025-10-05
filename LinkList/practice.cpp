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
}
};
int main() {
    List ll;

    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.print();
    return 0;
}
