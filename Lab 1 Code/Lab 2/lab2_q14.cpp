#include <iostream>
using namespace std;
int characterArray(char *p)
{
    int i=0;
    while (p[i]!='\0')
    {
        i++;
        
    }
    return i;
    
}
int main()
{
    char arr[100];
    cout<<"Enter some text \n";
     cin.getline(arr, 100);
    cout<<"Lenght of Text  :  "<< characterArray(arr);
    return 0;
}