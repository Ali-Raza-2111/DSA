#include <stdio.h>
#include <string.h>


void revString(char *ptr) {
    int len = strlen(ptr);
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
    }
}

int main() {
    char s[20] = "Ali Raza";   
    revString(s);               
    printf("Reversed string: %s\n", s); 
    return 0;
}
