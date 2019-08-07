#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main() {
	int *arr;
	int N;
	int sum = 0,ssum = 0;

	cin >> N;

	arr = (int *)malloc(sizeof(int)*N);
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	for (int i = 0;i < N;i++) {
		sum += arr[i];
		ssum += sum;
	}
	cout<<ssum<<endl;
	

	return 0;
}