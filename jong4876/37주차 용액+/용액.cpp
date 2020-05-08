#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	int N;
	vector<long long> vec;
	long long minVal = 3e9;

	cin >> N;
	for (int i = 0;i < N;i++) {
		long long num;
		cin >> num;
		vec.push_back(num);
	}
	
	// 이진탐색
	int leftIdx = 0, rightIdx = N - 1;
	long long minA, minB;

	while (leftIdx  < rightIdx) {

		// ** 최솟값 갱신과 인덱스 탐색은 별개
		int leftVal = vec[leftIdx];
		int rightVal = vec[rightIdx];

		if (minVal > abs(leftVal + rightVal)) {
			minVal = abs(leftVal + rightVal);
			minA = vec[leftIdx];
			minB = vec[rightIdx];
		}
		
		// 현재 합이 양수면 양수의 값을 줄이기
		if (leftVal + rightVal > 0) 
			rightIdx--;
		// 반대면 음수의 값을 줄이기
		else 
			leftIdx++;

	}


	cout << minA << " " << minB <<endl;
	return 0;
}