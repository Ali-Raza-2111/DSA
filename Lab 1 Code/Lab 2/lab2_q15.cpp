#include <iostream>
#include <climits>
using namespace std;
int * findMinOfArray(int arr[],int size)
{
    int ans = INT_MAX;
    for(int i=0;i<size;i++)
    {
        if(arr[i]<ans)
        {
            ans=arr[i];
        }
    }
    int *mini=new int(ans);
    return mini;
}
int main()
{
    int size=10;
    int arr[10]={1,234,45,434,53534,35,6545,343,645,3245};
    cout<<"Min of Array    :  "<<* findMinOfArray(arr,size);
     
    return 0;
}