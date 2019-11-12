#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string zipNum(string num, int reslen) {
	string answer = "";
	char max = -1;
	int startIdx;

	for (int i = 0;i <= num.length() - reslen;i++) {
		if (max < num[i]) {
			max = num[i];
			startIdx = i;
		}
	}
	for (int i = startIdx; i < num.length();i++) {
		answer += num[i];
	}

	return answer;
}


string solution(string number, int k) {
	string answer = "";
	string tmpAnswer = "";
	int startIdx; // 최댓값 찾기를 실시할 시작 인덱스
	char max = -1;
	int resLen = number.length() - k; // 결과값으로 나와야 하는 answer의 길이

	tmpAnswer = zipNum(number, resLen); // 처음으로 시작할 숫자부터 그 뒤의 수들 집합string
	// ex) 1231234 -> 31234 / k = 3

	answer += tmpAnswer[0]; // 첫 자리 수는 확정이므로 answer에 삽입
	resLen--; // 첫 자리는 정해졌으므로 실제 길이 줄임
	startIdx = 1; // 검사를 시작할 인덱스 = 1

	while (resLen > 0) { // 자릿수에 맞는 수들 중 최댓값들만 뽑아오는 과정
		char max = -1;
		int maxIdx;
		for (int i = startIdx;i <= tmpAnswer.length() - resLen;i++) {
			if (max < tmpAnswer[i]) {
				max = tmpAnswer[i];
				maxIdx = i;
			}
		}
		answer += max;
		startIdx = maxIdx+1;
		resLen--;
	}
	// 31234 -> 3234


	return answer;
}
