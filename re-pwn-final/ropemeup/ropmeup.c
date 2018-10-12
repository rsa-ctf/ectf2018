#include<stdio.h>
#include<stdlib.h>

int main() {

    //Present to give you the appropriate privileges.
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

    char buffer[30];
    printf("Enter a string: ");
    gets(buffer);
    printf("\nYou entered: %s\n", buffer);
    
    return 0;
}
