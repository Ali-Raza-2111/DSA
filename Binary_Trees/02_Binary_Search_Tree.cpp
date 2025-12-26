#include <iostream>
#include<vector>
using namespace std;


class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node *insertInBST(Node *root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(root->data>val){
        root->left=insertInBST(root->left,val);
    }
    else{
        root->right=insertInBST(root->right,val);
    }
    return root;
}

Node *buildTree(vector<int> arr){
    Node *root = NULL;
    for(int val:arr){
        root = insertInBST(root,val);
    }
    return root;
}

void inOrderTraversal(Node *root){
    if (root ==NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
int main() {
    vector<int> arr = {3,2,1,5,6,4};
    Node *root = buildTree(arr);
    inOrderTraversal(root);
    return 0;
}
