#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {

	if (a.second < b.second)
		return true;

	else
		return false;

}

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int presentTime = 0;
	vector<pair<int, int>> primaryQ;


	// 작은거 먼저 끝내기 위한 오름차순 정렬 필요
	for (int i = 0;i < jobs.size();i++) {
		primaryQ.push_back(pair<int, int>(jobs[i][0], jobs[i][1]));
	}

	sort(primaryQ.begin(), primaryQ.end(), compare);
	int size = primaryQ.size();
	int timeSum = 0;

	while (primaryQ.size() > 0) {
		int i;
		int flag = 0;

		// 현재 진행 가능한 프로세스 중에서 가장 작업시간 작은 프로세스 먼저
		for (int i = 0;i < primaryQ.size();i++) {
			if (primaryQ[i].first <= presentTime) {

				// 현재시간부터 작업완료 시간으로 이동
				presentTime += primaryQ[i].second;

				// 작업시간 + 지연시간 = 작업완료시간 - 시작시간
				timeSum += (presentTime - primaryQ[i].first);

				// 작업 완료 프로세스 제거
				primaryQ.erase(primaryQ.begin()+i);

				// 작업이 끝났으면 큐 갱신 후 새로 
				flag = 1;
				break;
			}
		}

		// 실행가능한 프로세스가 없으면 +1초씩
		if(flag == 0)
			presentTime++;
	}
	answer = timeSum / size;



	return answer;
}
