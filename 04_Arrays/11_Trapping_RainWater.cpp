#include <iostream>
#include <climits>
using namespace std;

void trap(int *arr,int n){
    int leftMax[20000],rightMax[20000];
    leftMax[0] = arr[0];
    rightMax[n-1] = arr[n-1];


    for (int i = 1; i < n; i++)
    {
        leftMax[i]  = max(leftMax[i-1],arr[i]);
    }

    for (int i = n-2; i >=0; i--)
    {
        rightMax[i] = max(rightMax[i+1],arr[i]);
    }
    
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int currentWater = min(leftMax[i],rightMax[i]) - arr[i];
        if (currentWater>0)
        {
            waterTrapped +=currentWater;
        }
        
    }

    cout<<"Water Trapped = "<<waterTrapped<<" ";
    
    
}
int main(){
    int heights[7] = {4,2,0,6,3,2,5};
    int n = sizeof(heights)/sizeof(int);
    trap(heights,n);
    return 0;
}