#include <iostream>
#include<climits>
using namespace std;

class Node{
private:
  int data;
  Node *next;
public:
    int getData(){
        return data;
    }

    Node* getNext(){
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
    Node *head;
    Node *tail;
public:
    List(){
        head = tail = NULL;
    }
    void print(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->getData()<<" ";
            temp = temp->getNext();
        }
        cout<<endl;
    }

    void insert(int val){
        Node *newNode = new Node();
        newNode->setData(val);
        newNode->setNext(NULL);
        if(head == NULL){
            head = tail = newNode;
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
    Node *current = head->getNext();
    Node *prev = head;
    while (current->getData() != val)
    {
        current = current->getNext();
        prev = prev->getNext();
    }
    prev->setNext(current->getNext());
    current->setNext(NULL);

    if (current->getNext() == NULL)
    {
        tail = prev;
    }
    delete current;
}

    void addBetween(int val,int val1){
        Node *temp = head;
        Node *newNode = new Node();
        newNode->setData(val);
        newNode->setNext(NULL);
        while(temp != NULL && temp->getData() != val1){
            temp = temp->getNext();
        }
        if(temp == NULL){
            return;
        }
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
    }

    void max(){
        Node *temp = head;
        int max = INT_MIN;
        while (temp !=NULL)
        {
            if (temp->getData() > max)
            {
                max = temp->getData();
                
            }
            temp =temp->getNext();
            
        }
        cout<<"Maxing value is "<<max<<endl;
    }

    void min(){
        Node *temp = head;
        int min = INT_MAX;
        while (temp !=NULL)
        {
            if (temp->getData() < min)
            {
                min = temp->getData();
                
            }
            temp =temp->getNext();
            
        }
        cout<<"Minimum value is "<<min<<endl;
    }

    void sort(){
        
        Node *temp = head;
        while (temp->getNext()!= NULL)
        {
            Node *current = head->getNext();
            Node *prev = head;
            while (current!= NULL)
            {
                if (prev->getData() > current->getData())
                {
                    int t = prev->getData();
                    prev->setData(current->getData());
                    current->setData(t);
                    // cout<<"Swapping "<<prev->getData()<<" and "<<current->getData()<<endl;
                }
                current = current->getNext();
                prev = prev->getNext();
                
            }
            temp = temp->getNext();
        }
        
    }
};

int main() {

    List myList;

    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);
    myList.insert(5);
    myList.print();
    myList.deleteValue(3);
    myList.print();
    myList.addBetween(6,4);
    myList.print();
    myList.max();
    myList.min();
    myList.sort();
    myList.print();
    
    
    return 0;
}
