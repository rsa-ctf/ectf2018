#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str1[] = "Come out of this vicuous circle and Capture it!!";
char str2[] = "\x06\x2c\x39\x23\x5b\x1d\x46\x02\x7f\x1a\x42\x11\x1a\x0f\x36\x17\x11\x52\x5d\x47\x51\x30\x44\x57\x7f\x50\x5d\x56\x1a\x33\x17\x69\x06\x06\x53\x7f\x73\x19\x42\x11\x12\x14\x5c\x18\x0c\x13\x49\x5c";

void print_vicious_circle() {

	for(int i = 0; i < 60; i++) {
		printf("+");
		sleep(0.001);
	}
}


int main() {
	

	printf("%s\n", str1);
	print_vicious_circle();
	char buf[48];

	for(int i = 0; i < 48; i++) {
		buf[i] = str1[i] ^ str2[i];
	}
	return 0;
}
