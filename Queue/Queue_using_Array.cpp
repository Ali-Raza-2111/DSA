#include <iostream>
using namespace std;
# define Queue_Size 5
class QueueArray{
    private:
    int queue[Queue_Size];
    int front;
    int rear;
    public:
    QueueArray(){
        front = -1;
        rear = -1;
    }

    int size(){
        return rear + 1;
    
    }
    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if(rear == Queue_Size - 1){
            return true;
        }else{
            return false;
        }
    }

    void Enqueue(int data){
        if (isFull()==true)
        {
            cout<<"Queue is Full"<<endl;
        }else{
            queue[++rear] = data;
            if (front == -1)
            {
                front = 0;
            }
            
        }
        
    }

    void Dequeue(){
        if (isEmpty()==true)
        {
            cout<<"Queue is Empty"<<endl;
        }else{
            front++;
        }
    }

    void PrintQueue(){
        if (isEmpty() == true)
        {
            cout<<"The queue is Empty"<<endl;
        }else{
            for (int i = front; i <= rear; i++)
            {
                cout<<queue[i]<<" ";
            }
            cout<<endl;
        }
        
    }
};
int main(){
    QueueArray q1;
    q1.Enqueue(100);
    
    q1.Enqueue(200);
    
    q1.Enqueue(300);
    
    q1.Enqueue(400);
    
    q1.Enqueue(500);
    q1.PrintQueue();
    
    return 0;
}