#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
map<int, int> numMap; // map을 통해 중복제거

bool isDecimal(int num) {
	// 소수여부 계산
	if (num == 0 || num == 1)
		return false;


	for (int i = 2;i < num;i++) {
		if (num % i == 0)
			return false;
	}

	return true;
}

int solution(string numbers) {
	int answer = 0;
	// next_permutaion을 위한 오름차순 정렬
	sort(numbers.begin(), numbers.end());

	// 길이가 1~ N 경우 순환
	for (int i = 1;i <= numbers.length();i++) {
		string strNum;
		for (int j = 0;j < i;j++) {
			strNum.push_back(numbers[j]);
		}
		int num = atoi(strNum.c_str());
		if (isDecimal(num))
			numMap.insert(pair<int, int>(num, 0));

		// 전체 경우에서 길이가 i만큼인 수를 떼서 소수여부 확인 **
		while (next_permutation(numbers.begin(), numbers.end())) {
			string strNum;
			for (int j = 0;j < i;j++) {
				strNum.push_back(numbers[j]);
			}
			num = atoi(strNum.c_str());
			if (isDecimal(num))
				numMap.insert(pair<int, int>(num, 0));
		}
	}
	return numMap.size();
}
