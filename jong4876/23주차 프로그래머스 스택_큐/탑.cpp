#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	queue<int> Q;
	int receiveIdx;

	for (int i = 0;i < heights.size();i++) {
		int presentHeight = heights[i];
		int flag = 0;
		for (int j = i;j >= 0;j--) {
			if (presentHeight < heights[j]) {
				answer.push_back(j + 1);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			answer.push_back(0);

	}




	return answer;
}