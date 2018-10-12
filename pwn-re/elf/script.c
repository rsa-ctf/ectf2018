#include<stdio.h>
#include<string.h>
int main() {

	char flag[] = "ECTF{g07_T0_kn0W_wh4T_4n_ELF_h4$_0x0910293102}";
	char str[100];
		for(int x = 0; x < strlen(flag); x++) {
			str[x] = flag[x] ^ 31;
		}

	printf("%s\n", str);

	return 0;
}
