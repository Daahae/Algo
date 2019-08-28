#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int arr[10];
	cin >> N;
	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3;i <= N;i++) {
		arr[i%10] = (arr[(i - 1)%10] + arr[(i - 2)%10])%15746;
	}

	cout << (arr[N%10]);
	return 0;
}

