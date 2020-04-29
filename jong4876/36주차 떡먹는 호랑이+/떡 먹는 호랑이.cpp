#include <string>
#include <vector>
#include <iostream>

using namespace std;
int D, K;

int main() {
	cin >> D >> K;

	int x[40];
	int y[40];

	// x, y, x+y
	x[1] = 1;
	x[2] = 0;
	x[3] = 1;

	y[1] = 0;
	y[2] = 1;
	y[3] = 1;

	// x+2y, 2x+3y ~~~
	for (int i = 4;i <= D;i++) {
		x[i] = x[i - 1] + x[i - 2];
		y[i] = y[i - 1] + y[i - 2];
	}

	// x[D] * A + y[D] * B = K
	int A, B;

	// A, B가 정수형으로 나올 떄 정답
	for (int i = 1;i <= K;i++) {
		int rest = K - (x[D] * i);
		if (rest % y[D] == 0) {
			A = i;
			B = rest / y[D];
			break;
		}
	}

	cout << A << endl;
	cout << B << endl;

	return 0;
}