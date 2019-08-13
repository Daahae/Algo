#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main() {
	int arr[9];
	int sum = 0;
	int heightSum = 0;
	int i, j;

	for (i = 0;i < 9;i++) {
		cin >> arr[i];
		heightSum += arr[i];
	}
	sort(arr, arr + 9);

	for (i = 0;i < 9;i++) {
		for (j = 0;j < 9;j++) {
			if (i != j) {
				sum = heightSum - (arr[i] + arr[j]);
				if (sum == 100)
					break;
			}
		}
		if (sum == 100)
			break;
	}


	for (int k = 0;k < 9;k++) {
		if (k != i && k != j)
			cout << arr[k] << endl;
	}



	return 0;
}