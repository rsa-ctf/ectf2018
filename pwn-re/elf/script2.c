#include<stdio.h>
#include<string.h>
int main() {

	char xor[] = "Z\\KYdx/(@K/@tq/R@hw+K@+q@ZSY@w+;@/g/&./-&,./-b";

	for(int i = 0; i < strlen(xor); i++)
		printf("%c", xor[i] ^ 31);
	
	printf("\n");
	return 0;
}
