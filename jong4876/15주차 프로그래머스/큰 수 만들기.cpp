#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(char a, char b) {
	return a > b;
}

string solution(string number, int k) {
	string answer = "";
	vector<char> stringNum;
	vector<int> edgeIdx;
	int startIdx; // 최댓값 찾기를 실시할 시작 인덱스
	char max = -1;

	for (int i = 0;i < number.length();i++)
		stringNum.push_back(number[i]);

	for (int i = 0;i < number.length() - k+1;i++) { // 뒤에서 N-k이상떨어져 있고 시작할 최댓값
		if (max < number[i]) {
			max = number[i];
			startIdx = i;
		}
	}


	k = k - startIdx;
	

	for (int i = startIdx;i < number.length() - k;i++) { // 퐁당퐁일때 빼기
		if (i == startIdx)
			continue;

		if (k == 0)
			break;

		if ((number[i - 1] > number[i]) && (number[i] < number[i + 1])) {
			edgeIdx.push_back(i);
			k--;
		}
	}

	int cnt = 0;
	if (edgeIdx.size() == 0) { //반례추가
		for (int i = startIdx;i < number.length();i++)
			answer += number[i];

		while (k > 0) {
			int min = -1;
			int minIdx;
			for (int i = 0;i < answer.length();i++) {
				if (min > answer[i]) {
					min = answer[i];
					minIdx = i;
				}
			}
			answer.erase(answer.begin() + minIdx);
			k--;
		}


		return answer;
	}

	for (int i = startIdx;i < number.length();i++) { // 앞에 제거한값 대입
		if (edgeIdx[cnt] == i && (edgeIdx.size()-1 >= cnt)) {
			int idx = edgeIdx[cnt];
			cnt++;
			continue;
		}

		answer += number[i];
	}

	while (k > 0) {
		int min = -1;
		int minIdx;
		for (int i = 0;i < answer.length();i++) {
			if (min > answer[i]) {
				min = answer[i];
				minIdx = i;
			}
		}
		answer.erase(answer.begin() + minIdx);
		k--;
	}

	return answer;
}
