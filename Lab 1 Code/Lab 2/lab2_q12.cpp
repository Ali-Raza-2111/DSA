#include <stdio.h>


void printValue(const int *ptr) {
    printf("Value: %d\n", *ptr);  
}

int main() {
    int x = 42;
    printValue(&x);

    return 0;
}
