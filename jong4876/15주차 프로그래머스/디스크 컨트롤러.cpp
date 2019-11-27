#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int workTime = 0;
vector<pair<int, int>> primaryQ; //들어온시점, 걸린 시간

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	
	return a.second < b.second;

}
// 들어온 시간순으로 수행하되, 비는 시간에는 최소 시간을 집어넣음

void printQ() {
	for (int i = 0;i < primaryQ.size();i++)
		cout << primaryQ[i].second << endl;
}

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int size;
	int timeSum = 0;

	for (int i = 0;i < jobs.size();i++) {
		primaryQ.push_back(pair<int, int>(jobs[i][0], jobs[i][1]));
	}
	size = primaryQ.size();

	sort(primaryQ.begin(), primaryQ.end(), compare);


	while (primaryQ.size() > 0) {
		int i;
		int flag = 0;
		
		for (i = 0;i < primaryQ.size();i++) {
			if (workTime >= primaryQ[i].first) { // 유휴시간 없이 대기하는 프로세스가 있다면
				workTime += primaryQ[i].second; // 결국에 총 걸리는 시간은 second의 총합임을 인지
				timeSum += (workTime - primaryQ[i].first); // 딜레이 된 시간 합
				primaryQ.erase(primaryQ.begin() + i);		
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			workTime++;
	}
	answer = timeSum / size;
	
	return answer;
}
