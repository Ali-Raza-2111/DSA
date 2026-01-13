#include <iostream>
#include<vector>
#include <queue>
using namespace std;


class Node{
private:
    int data;
    Node *left;
    Node *right;
public:
    Node(int val){
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

static int indx = -1;

Node *buildTree(vector<int> preorder){
    indx++;
    if (preorder[indx] == -1)
    {
        return nullptr;
    }

    Node *root = new Node(preorder[indx]);
    root->setLeft(buildTree(preorder));
    root->setRight(buildTree(preorder));
    return root;
}


void LevelOrder(Node *root){
    if(root == nullptr){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp == nullptr){
            if(!q.empty()){
                cout<<endl;
                q.push(nullptr);
                continue;
            }else{
                break;
            }
        }
        cout<<temp->getData()<<" ";
        if (temp->getLeft()!=nullptr)
        {
            q.push(temp->getLeft());
        }
        if (temp->getRight()!=nullptr)
        {
            q.push(temp->getRight());
        }
        
    }
    
}

void PreOrderTraversal(Node *root){
    if(root == nullptr){
        return;
    }

    cout<<root->getData()<<" ";
    PreOrderTraversal(root->getLeft());
    PreOrderTraversal(root->getRight());
}

void postOrderTraversal(Node *root){
    if(root == nullptr){
        return;
    }

    postOrderTraversal(root->getLeft());
    postOrderTraversal(root->getRight());
    cout<<root->getData()<<" ";
}


void InOrderTraversal(Node *root){
    if(root == nullptr){
        return;
    }

    InOrderTraversal(root->getLeft());
    cout<<root->getData()<<" ";
    InOrderTraversal(root->getRight());
}



Node *deletNode(Node *root,int key){
    if(root == nullptr){
        return root;
    }

    if (key<root->getData())
    {
        root->setLeft(deletNode(root->getLeft(),key));
    }else if(key > root->getData()){
        root->setRight(deletNode(root->getRight(),key));
    }else{
        if(root->getLeft() == nullptr && root->getRight() == nullptr ){
            delete root;
            return nullptr;
        }
        if (root->getLeft() == nullptr)
        {
            Node *temp = root->getRight();
            delete root;
            return temp;
        }else if (root->getRight() == nullptr)
        {
            Node *temp = root->getLeft();
            delete root;
            return temp;
        }

        Node *successor = root->getRight();
        while (successor->getLeft()!=nullptr)
        {
            successor = successor->getLeft();
        }

        root->setData(successor->getData());
        root->setRight(deletNode(root->getRight(),successor->getData()));
        
    }

    return root;
    
}

int main(){
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    Node*root = buildTree(preorder);

    LevelOrder(root);
    deletNode(root,2);
    cout<<endl;
    cout<<endl;
    LevelOrder(root);
    // PreOrderTraversal(root);
    // postOrderTraversal(root);
    // InOrderTraversal(root);
    return 0;
}