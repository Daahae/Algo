#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	
	return a.second < b.second;

}

// ** 짧은 작업시간을 가진 프로세스를 먼저 처리한다.
// presentTime을 1초씩 증가시키면서 해당 presentTime에 맞는 로직을 실행
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int size;
	int timeSum = 0;
	int presentTime = 0;
	vector<pair<int, int>> primaryQ; //들어온시점, 걸린 시간


	// 프로세스의 작업시간 기준으로 오름차순 정렬
	// -> 우선순위 큐 처럼 사용

	for (int i = 0;i < jobs.size();i++) 
		primaryQ.push_back(pair<int, int>(jobs[i][0], jobs[i][1])); 
	sort(primaryQ.begin(), primaryQ.end(), compare);

	while (primaryQ.size() > 0) { // 프로세스를 다 실행시킬 때까지
		int i;
		int flag = 0;
		
		for (i = 0;i < primaryQ.size();i++) {
			if (presentTime >= primaryQ[i].first) { // 유휴시간 없이 대기하는 프로세스가 있다면
				presentTime += primaryQ[i].second; // 바로 해당프로세스를 실행
				timeSum += (presentTime - primaryQ[i].first); // 딜레이 된 시간 역시 더해줌
				primaryQ.erase(primaryQ.begin() + i); // 실행된 프로세스 제거
				flag = 1;
				break;
			}
		}
		if(flag == 0) // 해당presentTime 에 실행할 수 있는 프로세스가 없다면
			presentTime++;  // 무의미하게 시간을 보냄, 어쩔수없음
	}
	answer = timeSum / size;
	return answer;
}
