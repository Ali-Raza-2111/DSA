#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;

  Node(int val){
    data = val;
    next = NULL;
  }
};

class List{
    Node *head;
    Node *tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if (head== NULL)
        {
            cout<<"LL is empty";
            return;
        }
        
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if (head == NULL)
        {
            cout<<"LL is empty\n";
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    void insert(int val,int pos){
        if (pos <0)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        if (pos == 0)
        {
            push_front(val);
        }
        Node *temp = head;
        for (int i = 0; i < pos-1; i++)
        {
            if (temp == NULL)
            {
                cout<<"Invalid position"<<endl;
                return;
            }
            
            temp = temp->next;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        
        
        
    }
    void print_ll(){
        Node *temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        
    }

    int search(int val){
        Node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }
};
        


int main() {
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.pop_front();
    ll.print_ll();
    ll.pop_back();
    ll.print_ll();
    return 0;
}
