#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main() {
	long N;
	long i;
	cin >> N;

	for (i = 1;i < N;i++) { // 생성자는 최대 N-1
		long sum = 0;
		long num = i;
		sum += num;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}

		if (N == sum)
			break;
	}
	if (i == N)
		cout << 0;
	else
		cout <<i;


	return 0;
}