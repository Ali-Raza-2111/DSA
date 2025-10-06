#include <iostream>
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

    void Delete(int val){
        if(head == NULL){
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        while(temp != NULL && temp->getData() != val){
            prev = temp;
            temp = temp->getNext();
        }
        if(temp == NULL){
            return;
        }
        if(prev == NULL){
            head = temp->getNext();
        }else{
            prev->setNext(temp->getNext());
        }
        if(temp == tail){
            tail = prev;
        }
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
};

int main() {

    List myList;


    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    myList.insert(40);
    myList.insert(50);

    cout << "Original list: ";
    myList.print();

    // Delete one value
    myList.Delete(30);
    cout << "After deleting 30: ";
    myList.print();

    // Delete nodes between 20 and 50
    myList.addBetween(20, 50);
    cout << "After deleting between 20 and 50: ";
    myList.print();

    // Another test with a new object
    List anotherList;
    anotherList.insert(5);
    anotherList.insert(15);
    anotherList.insert(25);

    cout << "Another list: ";
    anotherList.print();

    anotherList.Delete(15);
    cout << "Another list after deleting 15: ";
    anotherList.print();

    return 0;
}
