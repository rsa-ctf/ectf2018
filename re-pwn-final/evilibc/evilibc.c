#include<stdio.h>
#include<stdlib.h>

char str[] = "/bin/sh";

void func() {

	char buffer[40];
	printf("Can you use this address and discover libc's evilness??\n");
	printf("Address of \"system\" = %p\n", system);

	printf("Now, enter any string you want: \n");
	gets(buffer);
	printf("You entered: %s\n", buffer);
	return;
}

int main(int argc, char **argv) {

    //Present to give you the appropriate privileges.
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

    puts("Do you know what libc is?");
    sleep(2);
    puts("You'd probably know how nice and useful it is...");
    sleep(2);
    puts("Did you know how evil libc can get?");

    func();
    return 0;
}
