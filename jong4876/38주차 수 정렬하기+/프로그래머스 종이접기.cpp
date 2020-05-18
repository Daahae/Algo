#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> answer;

// 사이마다 0, 1을 번갈아 -> 이진트리
vector<int> solution(int n) {

	answer.push_back(0);

	for (int i = 2;i <= n;i++) {

		vector<int> tmpAnswer = answer;
		answer.push_back(0);

		for (int j = tmpAnswer.size()-1 ;j >= 0;j--) {	
			if (tmpAnswer[j] == 1)
				answer.push_back(0);

			else
				answer.push_back(1);
		}
	}
	return answer;
}

