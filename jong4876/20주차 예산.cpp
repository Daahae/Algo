#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {

	long underLimit = 0;
	long size = budgets.size();
	long maxVal = 0;

	sort(budgets.begin(), budgets.end());

	for (int i = 0;i < budgets.size();i++) {
		underLimit += budgets[i];

		if (budgets[i] > maxVal)
			maxVal = budgets[i];
	}

	if (underLimit <= M)
		return maxVal;

	underLimit = M;

	underLimit /= size; 
	// M을 사이즈로 나눈 값을 상한값으로 두고 시작
	//121

	int left = underLimit;
	int right = maxVal;

	
	while (1) {
		int mid = (left + right) / 2;
	
		long sum = 0;
		for (int i = 0;i < budgets.size();i++) {
			if (budgets[i] <= mid)
				sum += budgets[i];
			else {
				sum += mid;
			}

		}

		if (left >= right-1)
			return mid;


		if (sum > M) {
			right = mid;
		}
		else if (sum < M)
			left = mid;
		else
			return mid;


	}

}