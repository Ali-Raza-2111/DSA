#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

int main(){
    int tries = 1;
    srand(time(0));
    char randomChar = 'a' + rand() % 26;
    // cout<<"The random Character is "<<randomChar<<endl;
    char c;
    int score = 0;
    do
    {

        cout<<"Enter any character\t";
        cin>>c;
        if(c == randomChar){
            if (tries == 1)
            {
                score +=10000;
                
            }else if(tries == 2){
                score+=8000;
            }
            else if(tries == 3){
                score+=6000;
            }
            else if(tries == 4){
                score+=4000;
            }
            else if(tries == 5){
                score+=2000;
            }  
            break; 
        }
        tries++;
    } while (tries<=5);
    
    cout<<"Score is "<<score;
    return 0;
}