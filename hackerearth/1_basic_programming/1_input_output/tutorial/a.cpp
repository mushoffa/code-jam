#include <stdio.h>

const int nax = 1005;
char in[nax], out[nax];

void test_case() {
	int n;

	scanf("%d", &n);
	scanf("%s", in);

	n = n * 2;
	printf("%d\n", n);
	printf("%s\n", in);
}

int main() {
	// int T;
	// scanf("%d", &T);
	// for(int nr = 1; nr <= T; nr++) {
	// 	test_case();
	// }
	test_case();
}