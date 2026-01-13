#include <iostream>
using namespace std;


void funArr(){
    int size;
    cin>>size;

    int *ptr = new int[size];
    int x = 1;
    for(int i =0;i<size;i++){
        ptr[i] = x;
        cout<<ptr[i]<<" ";
        x++;
    }

    delete [] ptr;
}

int main(){
    funArr();
    return 0;
}