#include<stdio.h>
#include<stdlib.h>

int main() {

    char buffer[30];
    printf("Enter a string: ");
    gets(buffer);
    printf("\nYou entered: %s\n", buffer);
    
    return 0;
}