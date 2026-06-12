#include <iostream>
#include<climits>
using namespace std;

int main(){
    int size = 7;
    int arr[size] = {3,-4,5,4,-1,7,-8};

    int maxSum = INT_MIN;

    for (int st = 0; st < size; st++)
    {
        int currSum = 0;

        for (int end = st; end < size; end++)
        {
            currSum +=arr[end];
            maxSum = max(currSum,maxSum);
        }
        
    }
    

    cout<<"Maximum Sum is "<<maxSum;
    return 0;
}