#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void get_flag() {
    system("cat flag.txt");
}

int main(int argc, char **argv) {

    if(argc != 2) {
        fprintf(stderr, "Usage: $ %s <Argument>\n", argv[0]);
        return -1;
    }

    //Present to give you the appropriate privileges.
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

    char buffer[30];
    unsigned long x = 0;

    strcpy(buffer, argv[1]);

    if(x == 0){
        printf("Yaaa!! You are not getting it!!\n");
        return -1;
    }
    else if(x == 0xe9283f2a8b1c4601) {
        printf("Wow! You got it!\n");
        get_flag();
        return 0;
    }
}
