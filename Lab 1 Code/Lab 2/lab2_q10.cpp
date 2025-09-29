#include <stdio.h>


int sum(int *a, int *b) {
    return *a + *b; 
}

int main() {
    int x, y, result;

    printf("Enter first integer: ");
    scanf("%d", &x);
    printf("Enter second integer: ");
    scanf("%d", &y);

    result = sum(&x, &y);

    printf("Sum = %d\n", result);

    return 0;
}
