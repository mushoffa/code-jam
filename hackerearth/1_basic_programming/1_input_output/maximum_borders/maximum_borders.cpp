#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

// const int MAX_SIZE = 1000001;
// char in[MAX_SIZE];
// int in[MAX_SIZE];

void test_case() {
	int m;
	int n;

	int max_border = 0;
	int cur_border = 0;

	scanf("%d %d", &m,&n);
	char in[n];

	for(int i = 0; i < m; i++) {
		scanf("%s", in);

		cur_border = 0;
		for(int j = 0; j < n; j++) {
			if((in[j] == '#') && (in[j+1] == '#')) {
				cur_border++;
			}
		}

		cur_border++;
	
		if(cur_border > max_border) {
			max_border = cur_border;
		}
	}
	
	printf("%d", max_border);
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