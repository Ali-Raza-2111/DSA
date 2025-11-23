#include <iostream>
#include<vector>
#include<queue>
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

static int idx = -1;
Node * buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx]==-1){
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

//preorder Traversal
void preOrder(Node *root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}

void inOrderTraversal(Node *root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}


void postOrderTraversal(Node *root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}


void levelOrder(Node *root){
    queue<Node*> q;
    q.push(root);
    while (q.size()>0)
    {
        Node *temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
    
}
int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node *root = buildTree(preorder);
    // preOrder(root);
    // inOrderTraversal(root);
    // postOrderTraversal(root); 
    levelOrder(root);  
    return 0;
}
