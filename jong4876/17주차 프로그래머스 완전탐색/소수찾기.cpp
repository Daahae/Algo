#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
map<int, int> numMap; // map을 통해 중복제거

bool isDecimal(int num) {
	if (num == 0 || num == 1)
		return false;


	for (int i = 2;i < num;i++) {
		if (num % i == 0)
			return false;
	}

	return true;
}

void countDecimal() {

}

int solution(string numbers) {
	int answer = 0;
	
	
	sort(numbers.begin(), numbers.end());

	for (int i = 1;i <= numbers.length();i++) {
		string strNum;
		for (int j = 0;j < i;j++) {
			strNum.push_back(numbers[j]);
		}
		int num = atoi(strNum.c_str());
		if (isDecimal(num))
			numMap.insert(pair<int, int>(num, 0));

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