#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
	int N;
	long long arr[91];
	cin >> N;
	arr[1] = arr[2] = 1;

	for (int i = 3;i <= N;i++) {
		arr[i] = arr[i-1] +arr[i-2];
	}

	cout << arr[N];
	return 0;
}


