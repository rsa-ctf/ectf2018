#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void get_shell() {
	system("/bin/sh");
}

int main() {

	//Present to give you the appropriate privileges.
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);


    char buffer1[100];
    char buffer2[100];
    
    puts("Do you like cookies??");
    puts("I love the ones which are present in the memory!!");
    puts("Grab it and see if you like it or not!!");

    fgets(buffer1, sizeof(buffer1), stdin);
    printf(buffer1);

    puts("Hope you grabbed it!!");
    puts("\nNow, Enter any string you want!");
    gets(buffer2);

    return 0;
}
