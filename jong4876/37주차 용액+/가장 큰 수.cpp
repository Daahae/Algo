#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

bool compare(const string &a, const string &b) {

	if (a + b > b + a)
		return true;

	else
		return false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> stringNum;

	for (int i = 0;i < numbers.size();i++) {
		string str = to_string(numbers[i]);
		stringNum.push_back(str);
	}
	
	// 합병정렬
	sort(stringNum.begin(), stringNum.end(), compare);

	for (int i = 0;i < numbers.size();i++) 
		answer += stringNum[i];

	// 큰 수 대로 정렬해야 하기 떄문에 첫 숫자가 0이면 0
	if (answer[0] == '0')
		return "0";
	
	return answer;
}