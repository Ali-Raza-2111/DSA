#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};
int main() {
    Node *Node1 = new Node(10);
    cout<<Node1->data<<" "<<Node1->next<<endl;
    return 0;
}
