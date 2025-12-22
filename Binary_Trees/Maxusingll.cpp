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
class MaxHeap{
    public:
    Node* root;
    MaxHeap(){
        root=NULL;
    }

    
    void Insert(int val){
        Node* newnode=new Node(val);
        if(root==NULL){
        root=newnode;
        return;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(!temp->Left){
                temp->Left=newnode;
                newnode->Parent=temp;
                HeapifyUp(newnode);
                return;
            }
            else{
                q.push(temp->Left);
            }
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
        while(node->Parent!=NULL && node->Data >node->Parent->Data){
            swap(node->Data,node->Parent->Data);
            node=node->Parent;
        }
    }
    void Delete(){
        if(root==NULL)
        return;
        queue<Node*>q;
        q.push(root);
        Node* last=NULL;
        //find last node
        while(!q.empty()){
            last=q.front();
            q.pop();
            if(last->Left) q.push(last->Left);
            if(last->Right) q.push(last->Right);
        }
        //replace root data with last node data
        root->Data=last->Data;
        if(last->Parent!=NULL){
            if(last->Parent->Left==last)
            last->Parent->Left=NULL;
            else
            last->Parent->Right=NULL;
        }
        delete last;
        HeapifyDown(root);
    }
    void HeapifyDown(Node* node){
      while(node!=NULL){
        Node* largest=node;
        //check left child
        if(node->Left!=NULL && node->Left->Data> largest->Data)
        largest=node->Left;
        //check right child
        if(node->Right!=NULL && node->Right->Data> largest->Data)
        largest=node->Right;
        if(largest==node)
        break;
        swap(node->Data,largest->Data);
        node=largest;
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
    MaxHeap h;
    h.Insert(40);
    h.Insert(4);
    h.Insert(20);
    h.Insert(1);
    h.Print();
    cout<<"\nAfter Deleting...";
    h.Delete();
    h.Print();
}