#include<stdio.h>
#include<stdlib.h>

void getflag() {
    system("cat flag.txt");
}


int main(void) {

    unsigned int x, y;
    printf("Enter an address where you want write 4 bytes of data: ");
    scanf("%x", &x);

    printf("\nEnter the 4 bytes you want to write in that address: ");
    scanf("%x", &y);

    *(unsigned int *)x = y;

    puts("\nDo you know GOT?\n");

    return 0;
}