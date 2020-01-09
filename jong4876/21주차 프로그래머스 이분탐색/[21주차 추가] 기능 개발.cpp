#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> Q;
	vector<int> waitWork; //대기작업 집단

	for (int i = 0;i < progresses.size();i++) {
		int restWork = 100 - progresses[i];
		int day = restWork / speeds[i];
		
		if (restWork% speeds[i] != 0)
			day++;

		Q.push(day);
	}
	// Q <- 7 3 9
	int beforeWork = 101;
	int publishCnt = 0;

	while (!Q.empty()) {
		if (Q.front() <= beforeWork) {
			waitWork.push_back(Q.front());
		}
		else {
			answer.push_back(waitWork.size());
			waitWork.clear();
			waitWork.push_back(Q.front());
		}
		beforeWork = Q.front();
		Q.pop();
	}

	
	answer.push_back(waitWork.size());


	return answer;
}