#include<iostream>
using namespace std;
class node
{
private:
    int data;
    node* right;
    node* left;

    
public:
     node(){
        data=0;
        left=NULL;
        right=NULL;
     }
     node(int n){
        data=n;
        right=NULL;
        left=NULL;
     }
     int getdata(){
        return data;
     }
    void setdata(int data)
    {
        this->data=data;
    }
    node* getleft(){
        return left;
    }
    void setleft(node* left){
        this->left=left;
    }
    node* getright(){
        return right;
    }
    void setright(node* right){
        this->right=right;
    }
    bool isleaf(){
        return (left==NULL&&right==NULL);
    }

};

int main(){

    
return 0;
}