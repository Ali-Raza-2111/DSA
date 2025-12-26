#include<iostream>
using namespace std;
class MinHeap{
    public:
    int a[100];
    int size;
    MinHeap(){
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
        a[size]=value;   //placed value at end
        int i=size;      //index of inserted value
        size++;

        while(i>0){
            int p=parent(i);   //find parent index using formula

            if(a[p]>a[i]){     //if parent>child->swap
                swap(a[p],a[i]);
                i=p;          //move to parent index
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
        //move last element to root
        a[0]=a[size-1];
        size--;
        int i=0;
        while(true){
            int l=left(i);
            int r=right(i);
            int smallest=i;
            if(l<size && a[l]<a[smallest]){
                smallest=l;
            }
            if(r<size && a[r]<a[smallest]){
                smallest=r;
            }
            if(smallest!=i){
                swap(a[i],a[smallest]);
                i=smallest;
            }
            else{
                break;   //both child larger then break
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
    MinHeap h;
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