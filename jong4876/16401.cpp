#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int possible(int *arr, int M, int N, int len){ // 분배가 가능한지

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += arr[i] / len;
	}
	if (cnt >= M)
		return 1;
	return 0;

}
int compare(const void *a, const void *b){    // 오름차순 비교 함수 구현
	int num1 = *(int *)a;
	int num2 = *(int *)b;   

	if (num1 > num2)    
		return -1;      

	if (num1 < num2)   
		return 1;       

	return 0; 
}
int main() {
	int *arr;
	int N, M;
	int cnt;
	int low=0, max;


	scanf("%d %d", &M, &N);
	arr = (int *)malloc(sizeof(int)*N);

	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, N, sizeof(int), compare);
	max = arr[0];

	int result = 0;
	while (low <= max){
		int mid = (low + max) / 2;
		if (possible(arr,M,N,mid)){
			result = mid;
			low = mid + 1;
		}else
			max= mid - 1;
	}
	printf("%d", result);

	
	system("pause");
	return 0;
}