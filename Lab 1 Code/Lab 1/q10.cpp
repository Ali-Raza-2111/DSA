#include <iostream>
using namespace std;

int main(){
    string s;
    cout<<"Enter a string\t";
    getline(cin,s);
    
    for (int i = s.length(); i >= 0; i--)
    {
        cout<<s[i];
    }
    
    return 0;
}