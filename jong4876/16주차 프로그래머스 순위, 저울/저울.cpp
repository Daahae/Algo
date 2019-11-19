#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000000]; //  시간오바시 확인

int solution(vector<int> weight) {
	int answer = 0;

	sort(weight.begin(), weight.end());

	for (int i = 0;i < weight.size();i++)
		dp[weight[i]] = 1; // 만들 수 있는 무게값 1체크

	while (1) {
		answer++;
		int tmpAnswer = answer;
		int sum = 0;
		int maxUnderAnswer;
		int idx;
		for (int i = 1;i < weight.size();i++) {
			if (weight[i] >= answer) {
				maxUnderAnswer = weight[i - 1];
				idx = i;
			}
		}
		
		int successFlag = 0; //  저울추로 측정 가능한지 여부
		for (int i = idx; i >= 0;i--) {
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
