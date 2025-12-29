#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int Data;
    Node* Left;
    Node* Right;
    Node* Parent;
    Node(int val){
        Data=val;
        Left=Right=Parent=NULL;
    }
};
class MinHeap{
    public:
    Node* root;
    MinHeap(){
        root=NULL;
    }
    void Insert(int val){
        Node* newnode=new Node(val);
        //if there is no root->empty heap
        if(!root){
            root=newnode;
            return;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();

            //if left child empty
            if(!temp->Left){
                temp->Left=newnode;
                newnode->Parent=temp;
                HeapifyUp(newnode);   //fix heap property
                return;
            }
            else{
                q.push(temp->Left);
            }
            //right child empty
            if(!temp->Right){
                temp->Right=newnode;
                newnode->Parent=temp;
                HeapifyUp(newnode);
                return;
            }
            else{
                q.push(temp->Right);
            }
        }
    }
    void HeapifyUp(Node* node){
        //jab tk parent exist krta or child chota
        while(node->Parent!=NULL && node->Data <node->Parent->Data){
            swap(node->Data,node->Parent->Data);
            node=node->Parent;    //move up
        }
    }
    //Delete Min-(root delete)
    void DeleteMin(){
        if(root==NULL) return;
        //find the last node
        queue<Node*>q;
        q.push(root);
        Node* last =NULL;
        while(!q.empty()){
            last=q.front();
            q.pop();
            if(last->Left) q.push(last->Left);
            if(last->Right) q.push(last->Right);
        }
        //replace root data with last node data
        root->Data=last->Data;
        //remove last node
        if(last->Parent!=NULL){
            if(last->Parent->Left==last)
            last->Parent->Left=NULL;
            else
            last->Parent->Right=NULL;
        }
        delete last;

        //fix heap property
        HeapifyDown(root);
    }
    void HeapifyDown(Node* node){
        while(node!=NULL){
            Node* smallest=node;

            //check left child
            if(node->Left!=NULL && node->Left->Data<smallest->Data){
                smallest=node->Left;
            }
            //check right child
            if(node->Right!=NULL && node->Right->Data<smallest->Data){
                smallest=node->Right;
            }
            //if already node is smallest
            if(smallest==node)
            break;
            //else
            swap(node->Data,smallest->Data);
            node=smallest;
        }
    }
    //Print
    void Print(){
        if(root==NULL){
            cout<<"Heap is empty";
            return;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            cout<<curr->Data<<" ";
            if(curr->Left!=NULL)
            q.push(curr->Left);
            if(curr->Right!=NULL)
            q.push(curr->Right);
        }
    }
};
int main(){
    MinHeap h;
    h.Insert(40);
    h.Insert(4);
    h.Insert(20);
    h.Insert(1);
    h.Print();
    cout<<"\nAfter Deleting: ";
    h.DeleteMin();
    h.Print();
}