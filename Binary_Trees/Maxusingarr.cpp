#include<iostream>
using namespace std;
class MaxHeap{
    public:
    int a[100];
    int size;
    MaxHeap()
    {
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
    void Insert(int value){
        a[size]=value;
        int i=size;
        size++;
        while(i>0){
            int p=parent(i);
            if(a[p]<a[i]){
                swap(a[p],a[i]);
                i=p;
            }
            else{
                break;
            }
        }
    }
    int Delete(){
        if(size==0)
        return -1;
        int root=a[0];
        a[0]=a[size-1];
        size--;
        int i=0;
        while(true){
            int l=left(i);
            int r=right(i);
            int largest=i;
            if(l<size && a[l]>a[largest]){
                largest=l;
            }
            if(r<size && a[r]>a[largest]){
                largest=r;
            }
            if(largest!=i){
                swap(a[i],a[largest]);
                i=largest;
            }
            else{
                break;
            }
        }
        return root;
    }
    void Print(){
        for(int i=0;i<size;i++){
            cout<<a[i]<<" ";
        }
    }
};
int main(){
    MaxHeap h;
    h.Insert(10);
    h.Insert(4);
    h.Insert(15);
    h.Insert(20);
    h.Insert(3);
    h.Insert(8);
    cout<<"Heap after insertion: ";
    h.Print();
    cout<<"\nAfter deletion: ";
    h.Delete();
    h.Print();
}