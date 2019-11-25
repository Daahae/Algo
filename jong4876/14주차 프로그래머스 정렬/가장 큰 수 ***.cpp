#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

//**** string 비교 -> 말그대로 뒤에 a+b문자를 붙인 값을 서로 비교
bool compare(const string &a, const string &b) {
	if (a + b > b + a)
		return true;
	else
		return false;

}

string solution(vector<int> numbers) {
	string answer = "";
	vector <string> stringNum;

	for (int i = 0;i < numbers.size();i++) {
		stringNum.push_back(to_string(numbers[i]));
		
	}

	// string 비교 기준으로 정렬
	sort(stringNum.begin(), stringNum.end(), compare);

	

	//string 은 pushback 대신 그냥 더하기로도 가능
	for (int i = 0;i < stringNum.size();i++) {
		answer+=stringNum[i];
	}

	// 모든 배열에 0일때 제외
	if (answer[0] == '0')
		return "0";


	

	return answer;
}
