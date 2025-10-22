#include <iostream>
#include<cstring>
using namespace std;

void reverseArray(char word[],int n){
    int start = 0,end = n-1;
    while (start<end)
    {
        swap(word[start],word[end]);
        start++;
        end--;
    }
    
}
int main(){
    char word[] = "CODE";
    reverseArray(word,strlen(word));
    cout<<word<<endl;
    return 0;
}