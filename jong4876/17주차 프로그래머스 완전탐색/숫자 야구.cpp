#include <string>
#include <vector>

using namespace std;

bool isDuplicateOrZero(string num) { // 중복, 0여부 확인

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (num[j] == '0')
				return true;
			if (num[i] == num[j]) {
				if (i != j)
					return true;
			}			
		}
	}
	return false;
}



int solution(vector<vector<int>> baseball) {
	int answerCnt = 0;
	int answer = 123;
	// 다해보기?

	while (answer <= 987) { // 123~987 수 전부 대입해서 찾아보기
		int answerFlag = 1;
		string strAnswer = to_string(answer);
		if (isDuplicateOrZero(strAnswer)) {
			answer++;
			continue;
		}

		for (int i = 0;i < baseball.size();i++) {// 4
			string num = to_string(baseball[i][0]);
			int answerStrike = baseball[i][1];
			int answerBall = baseball[i][2];
			int strike = 0;
			int ball = 0;

			for (int j = 0;j < 3;j++) {
				for (int k = 0;k < 3;k++) {
					if (strAnswer[j] == num[k]) {
						if (j == k) { // strike
							strike++;
						}
						else { //ball
							ball++;
						}
					}
				}
			}
			// 답이 아니라면 다른값이랑 비교하게 break
			if (answerStrike != strike || answerBall != ball) {
				answerFlag = 0;
				break;
			}
		}
		if (answerFlag == 1) // 조건에 맞는 값일 때, count 증가
			answerCnt++;

		answer++;
	}

	return answerCnt;
}