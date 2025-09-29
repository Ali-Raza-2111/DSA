#include <stdio.h>

int main() {
    static char name1[50], name2[50], name3[50];
    char *names[3] = {name1, name2, name3}; 

    for (int i = 0; i < 3; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%49s", names[i]);  
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < 3; i++) {
        printf("Student %d: %s\n", i + 1, names[i]);
    }

    return 0;
}
