#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000000]; //  시간오바시 확인

int solution(vector<int> weight) {
	int answer = 0;

	sort(weight.begin(), weight.end());

	while (1) {
		answer++;
		int tmpAnswer = answer;
		int sum = 0;
		int maxUnderAnswer;

		int successFlag = 0; //  저울추로 측정 가능한지 여부
		for (int i = weight.size() -1 ; i >= 0;i--) {
			if (tmpAnswer - weight[i] < 0) {
				continue;
			}

			tmpAnswer -= weight[i];
			if (tmpAnswer == 0) {
				successFlag = 1;
				break;
			}

		}
		if (successFlag == 0)
			return answer;
	}
}
