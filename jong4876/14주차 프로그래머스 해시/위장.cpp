#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int factorial(int n) {

	int result = 1;

	for (int i = 1; i <= n; ++i)
		result *= i;

	return result;
}



int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map <string, int> clothMap; // 옷 종류, 개수

	for (int i = 0;i < clothes.size();i++) {
		clothMap[clothes[i][1]] = 0;
	}

	for (int i = 0;i < clothes.size();i++) {
		clothMap[clothes[i][1]]++;
	}
	// 더하기 1씩해서 싹다 곱하자

	for (auto it = clothMap.begin();it != clothMap.end();it++) {
		answer *= (it->second + 1);
	}
	answer - 1;




	return answer;
}