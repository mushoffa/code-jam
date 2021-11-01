#include <stdio.h>
#include <stdlib.h>

const int max = 1000001;
char in[max];

void test_case() {
	bool a,i,u,e,o;

	a = false;
	i = false;
	u = false;
	e = false;
	o = false;
	
	scanf("%s", in);

	for(int j = 0; j < max; j++) {
		if(in[j] == '\0') {
			break;
		}

		switch(in[j]) {
			case 'a':
			case 'A': a = true;
				break;

			case 'i':
			case 'I': i = true;
				break;

			case 'u':
			case 'U': u = true;
				break;

			case 'e':
			case 'E': e = true;
				break;

			case 'o':
			case 'O': o = true;
				break;
		}
	}

	if(a && i && u && e && o) {
			printf("lovely string");
	} else {
			printf("ugly string");
	}

	puts("");
}

int main() {
	int T;
	scanf("%d", &T);

	// tc means test case
	for(int tc = 1; tc <= T; tc++) {
		test_case();
	}
}