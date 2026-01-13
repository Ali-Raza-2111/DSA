#include <iostream>
using namespace std;
class minHeap{
    public:
    int arr[100];
    int size;
    minHeap(){
        size=0;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    void insert(int value){
        arr[size]=value; //place value at end
        int index = size; //index of inserted value
        size++;
        while (index>0)
        {
            int pare = parent(index); //find parent index using formula
            if (arr[pare]>arr[index]) //if parent>child->swap
            {
                swap(arr[pare],arr[index]);
                index=pare; //move to parent index
            }
            else{
                break;
            }
            
        }
        
    }
}
int main() {
    
    return 0;
}
