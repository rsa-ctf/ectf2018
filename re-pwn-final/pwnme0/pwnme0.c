#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void func();

int main(int argc, char **argv) {
	

	unsigned int gid, uid;
	gid = geteuid();
	uid = geteuid();

	printf("gid %d\nuid %d\n", gid, uid);

	setresgid(gid, gid, gid);
	setresuid(uid, uid, uid);

	system("/bin/sh");
	
	return 0;
}
