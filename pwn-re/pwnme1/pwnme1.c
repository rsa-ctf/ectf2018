#include<stdio.h>
#include<stdlib.h>

void func();

int main(int argc, char **argv) {

    //Present to give you the appropriate privileges. 
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

    printf("Executing function \"func\"");
    func();
    
    return 0;
}

void func() {

    printf("\nYou are reading the system.log file!\n");
    system("cat system.log");
    return;
}
