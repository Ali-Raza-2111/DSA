#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;

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

Node * InsertInBST(Node *root,int info){
    if(root == NULL){
        return new Node(info);
    }

    if(root->getData() > info){
        root->setLeft(InsertInBST(root->getLeft(),info));
    }else if (root->getData() < info)
    {
        root->setRight(InsertInBST(root->getRight(),info));
    }else{
        cout<<"Duplicate Nodes "<<endl;
    }
    return root;    
}


void InOrder(Node* root)
{
    if(  root != NULL ) 
    {
        InOrder(root->getLeft());
        cout << root->getData()<<" ";
        InOrder( root->getRight());
    }
}


void PreOrder(Node *root){
    if (root !=NULL)
    {
        cout << root->getData()<<" ";
        PreOrder(root->getLeft());
        PreOrder( root->getRight());
    }
}


void PostOrder(Node *root){
    if (root !=NULL)
    {
        PostOrder(root->getLeft());
        PostOrder( root->getRight());
        cout << root->getData()<<" ";
    }
}

Node * findMininum(Node *root){
    if(root == NULL){
        return NULL;
    }
    if (root->getLeft() == NULL)
    {
        return root;
    }

    return findMininum(root->getLeft());
    
}

int main(){
    Node *root = new Node(5);

    InsertInBST(root,3);
    InsertInBST(root,6);
    // cout<<"Inorder Traversal......."<<endl;
    // InOrder(root);
    // cout<<"Preorder Traversal......."<<endl;
    // PreOrder(root);
    // cout<<"Postorder Traversal......."<<endl;
    // PostOrder(root);

    Node* min = findMininum(root);
    cout<<min->getData();
    return 0;
}