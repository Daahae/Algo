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

	// 예산안으로 전부 처리 가능하면 최댓값 리턴
	if (underLimit <= M)
		return maxVal;

	// 처리 불가능이면 하한값 변경
	underLimit = M;

	underLimit /= size; 
	// M을 사이즈로 나눈 값 -> 모든 도시에 공평하게 줄 수 있는 값
	//121


	int left = underLimit;
	int right = maxVal;

	
	while (1) {

		// sum값이 M 과 유사한 방향으로 나아가기 위한 이분탐색
		// mid = 가상의 상한액
		int mid = (left + right) / 2;
	
		long sum = 0;
		for (int i = 0;i < budgets.size();i++) {
			// 상한액 보다 작은값 = 그냥더하고, 큰값 = 상한액으로 더하기
			if (budgets[i] <= mid)
				sum += budgets[i];
			else {
				sum += mid;
			}
		}

		// 이를 통해 나온 sum에 대해서 이분탐색
		// 오차 1?
		if (left >= right-1) 
			return mid;

		if (sum > M) 
			right = mid;
		
		else if (sum < M)
			left = mid;
		else
			return mid;


	}

}
