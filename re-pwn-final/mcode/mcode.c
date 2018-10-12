#include<stdio.h>
#include<stdlib.h>

int main() {

	//Present to give you the appropriate privileges.
    unsigned int gid = geteuid();
    unsigned int uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

	char buffer[100];
	printf("Whatever you enter, it will be executed: \n");
	fgets(buffer, sizeof(buffer), stdin);

	void (*funcptr)();
	funcptr = buffer;

	funcptr();

	return 0;
}
