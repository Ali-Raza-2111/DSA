#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node *left;
    Node *right;
public:
    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    int getData() { return data; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }

   
    void setData(int val) { data = val; }
    void setLeft(Node* l) { left = l; }
    void setRight(Node* r) { right = r; }

    bool isLeaf() { return (left == nullptr && right == nullptr); }

};

Node * InsertInBST(Node *root,int value){
    if(root == NULL){
        return new Node(value);
    }

    if (value == root->getData())
    {
        cout<<"Duplicate Node"<<endl;
        return root;
    }
    
    if (value<root->getData())
    {
        root->setLeft(InsertInBST(root->getLeft(),value));
    }else{
        root->setRight(InsertInBST(root->getRight(),value));
    }

    return root;
    
}


void InOrderTraversal(Node *root){
    if (root != NULL)
    {
        InOrderTraversal(root->getLeft());
        cout<<root->getData()<<" ";
        InOrderTraversal(root->getRight());
    }
    
}


void PreOrderTraversal(Node *root){
    if (root!= NULL)
    {
        cout<<root->getData()<<" ";
        PreOrderTraversal(root->getLeft());
        PreOrderTraversal(root->getRight());
    }
    
}

void PostOrderTraversal(Node *root){
    if (root != NULL)
    {
        PostOrderTraversal(root->getLeft());
        PostOrderTraversal(root->getRight());
        cout<<root->getData()<<" ";
    }
    
}



Node *FindMinimum(Node *root){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->getLeft() == NULL)
    {
        return root;
    }

    return FindMinimum(root->getLeft());
    
    
}
int main(){
    Node *root = new Node(50);
    InsertInBST(root,30);
    InsertInBST(root,70);
    InsertInBST(root,20);
    InsertInBST(root,40);
    InsertInBST(root,60);
    InsertInBST(root,80);
    // InOrderTraversal(root);
    // PreOrderTraversal(root);
    PostOrderTraversal(root);
    cout<<endl;
}