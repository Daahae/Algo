//10250
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int T, H, W, N;
	int *arr;

	scanf("%d", &T);
	arr = (int *)malloc(sizeof(int)*T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &H, &W, &N);

		int mok = (N - 1) / H; // 호실 뒤번
		int rest = (N - 1) % H; // 호실 앞번

		int floor = rest + 1;
		int distance = mok + 1;

		int front = floor * 100;

		arr[i] = front + distance;
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", arr[i]);
	}

	//system("pause");
	return 0;
}

