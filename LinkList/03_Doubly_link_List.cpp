#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;


    public:
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

};

class list{
    public:
    Node *head;
    Node *tail;
    void pushFront(int val){
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        
    }
    void print_ll(){
        Node *temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        
    }

};
int main(){
     list ll;
     ll.pushFront(2);
     ll.pushFront(3);
     ll.pushFront(4);
    ll.print_ll();
    return 0;
}