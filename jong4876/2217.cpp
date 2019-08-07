#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
bool desc(int a, int b) {
	return a > b;
}
int main() {
	int *arr;
	int N;
	int max;

	cin >> N;
	arr = (int *)malloc(sizeof(int)*N);


	for (int i = 0;i < N;i++)
		cin >> arr[i];

	sort(arr, arr + N,desc);// 내림차순 정렬

	max = arr[0];
	for (int i = 1;i < N;i++) {
		int sum = arr[i] * (i + 1);
		if (max <= sum)
			max = sum;
	}
	cout << max;

	return 0;
}
