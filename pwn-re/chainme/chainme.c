#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int var1 = 0;
int var2 = 0;
int var3 = 0;

void chainme() {
    char buffer[20];
    printf("Enter a string: ");
    read(0, buffer, 200);
    printf("\n%s\n", buffer);
}

void func1(unsigned a) {

    asm("pop %eax");
    asm("pop %eax");
    asm("pop %eax");
    asm("pop %eax");
    asm("movl %esp, %ebp");



    if(a == 0xcafebabe && var2 == 20 && var3 == 30)
        var1 = 10;
    else {
        printf("Sorry. Try again!\n");
        exit(1);
     }
}

void func2(unsigned a, unsigned b) {

    asm("pop %eax");
    asm("pop %eax");
    asm("pop %eax");
    asm("pop %eax");
    asm("pop %eax");
    asm("movl %esp, %ebp");
    

    if(a == 0xdeadbeef && b == 0xef984aeb && var3 == 30)
        var2 = 20;
    else {
        printf("Sorry. Try again!\n");
        exit(1);
    }
}

void func3(unsigned a, unsigned b, unsigned c) {

    if(a == 0x981a6836 && b == 0x3e8b2391 && c == 0x1e284037)
        var3 = 30;
    
    else {
        printf("Sorry. Try again!\n");
        exit(1);
    }

    
}



int main() {

    //Present to give you the appropriate privileges.
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

    printf("Calling func!\n");
    chainme();

    if(var1 == 10 && var2 == 20 && var3 == 30)
        system("cat flag.txt");

    return 0;
}
