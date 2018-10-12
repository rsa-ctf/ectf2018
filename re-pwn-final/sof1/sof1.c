#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long unsigned int a = 0;

void func1() {

    char buffer[50];
    gets(buffer);
    printf("%s\n", buffer);
}

void func2() {
    a = 0xe3b8c1309390209f;
}


int main(int argc, char **argv) {

    //Present to give you the appropriate privileges.
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

    func1();

    if(a == 0xe3b8c1309390209f) {
        system("cat flag.txt");
    }

    else 
        printf("Hehe, you won't get it\n");

    return 0;
}