#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main() {
	int N, K;
	int *arr;
	int sum=0, tsum=0;
	int i;
	int st, end;
	int half;
	int cnt = 0;
	cin >> N >> K;

	arr = (int *)malloc(sizeof(int)*N);
	for (i = 0;i < N;i++) {
		cin >> arr[i];
	}
	st = 0;
	end = N - 1;
	
	while (1) {
		if (st >= end)
			break;

		half = (st + end) / 2;
		if (arr[half] > K)
			end = half - 1;

		else if (arr[half] < K)
			st = half+1;
	}
	for (int i = st;i >= 0;i--) {
		while (1) {
			//반복문 안돌리는 조건
			if ((K-sum)%arr[i] == 0) {
				cnt += (K - sum) / arr[i];
				sum = K;
				break;
			}
			else if (sum < K) {
				if (sum + arr[i] > K) // max 이상이면 중지
					break;
				sum += arr[i];
				cnt++;
			}
		}
		if (sum == K)
			break;
	}
	printf("%d", cnt);
	

	return 0;
}