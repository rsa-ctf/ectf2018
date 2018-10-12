#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void grant_shell() {
    system("/bin/sh");
}

void check_arg(unsigned char *arg) {

    if(strlen(arg) != 64)
        return;
    
    unsigned long *ptr, counter = 0, sum = 0;
    ptr = (unsigned long *)arg;

    

    for(int i = 0; i < 8; i++) {
        sum = sum + *ptr;
        printf("sum = 0x%lx, *ptr = 0x%lx\n", sum, *ptr);
        ptr++;
    }

    if(sum == 0xcafebabedeadbeef) {
        printf("You got it!\n");
        grant_shell();
    }

    else {
        printf("Sorry, you can't get it!\n");
        return;
    }

    return;
}



int main(int argc, unsigned char **argv) {

    if(argc != 2) {
        fprintf(stderr, "Usage: $ %s <An Argument>\n", argv[0]);
        return -1;
    }

    //Present to give you the appropriate privileges.
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

    check_arg(argv[1]);
    return 0;
}