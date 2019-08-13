#include <stdio.h>
#pragma warning(disable:4996)

int main() {

	int N;
	int cnt = 0;
	int sum;
	int min = 9999;
	int max5;
	int max3;
	int i, j;

	scanf("%d", &N);

	max5 = N / 5;
	max3 = N / 3;

	for (i = 0;i <= max5;i++) {
		for (j = 0;j <= max3;j++) {
			sum = i * 5 + j * 3;
			if (sum == N) {
				if (min > i+j)
					min = i+j;
			}
		}
	}
	if (min == 9999)
		min = -1;


	printf("%d",min);
	//system("pause");
	return 0;
}
