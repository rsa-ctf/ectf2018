#include<stdio.h>
#include<sys/mman.h>

int main() {

    //Present to give you the appropriate privileges. 
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

    char buffer[100];
    puts("Did you know mprotect can be used to attack the system?");
    printf("There you go - the address of mprotect: %p\n", mprotect);

    printf("\nEnter a string which gets stored at ths address: %p\n", buffer);
    read(0, buffer, 300);

    return 0;
}
