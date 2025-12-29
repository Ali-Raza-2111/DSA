#include <iostream>
using namespace std;
bool containDuplicate(int *arr,int n){
    int  a= 0;
    for (int i = a+1; i < n; i++)
    {
        if (arr[a] == arr[i])
        {
            return true;
        }

        if (i == n-1)
        {
            a++;
            i = a;
        }
    }
    return false;

}
int main(){
    int arr[4] = {1,2,3,4};
    int n = sizeof(arr)/ sizeof(int);
    cout<<containDuplicate(arr,n); 
    return 0;
}