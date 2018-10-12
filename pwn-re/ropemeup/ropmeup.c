#include<stdio.h>
#include<stdlib.h>

int main() {

<<<<<<< HEAD
    //Present to give you the appropriate privileges.
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

=======
>>>>>>> 9d147b6875e430acce3ca1c3ac35f35441aeed93
    char buffer[30];
    printf("Enter a string: ");
    gets(buffer);
    printf("\nYou entered: %s\n", buffer);
    
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 9d147b6875e430acce3ca1c3ac35f35441aeed93
