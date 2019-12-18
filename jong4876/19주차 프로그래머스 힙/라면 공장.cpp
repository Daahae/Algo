#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second > b.second;
}

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	vector<pair<int, int>> PQ;
	int day = 0;

	for (int i = 0;i < dates.size();i++) 
		PQ.push_back(pair<int, int>(dates[i], supplies[i]));

	//supplies 기준 내림차순 정렬
	sort(PQ.begin(), PQ.end(), compare); 

	// 다 쓰고 시작
	day += stock; 

	//day는 현재 날짜, k넘어가면 의미없음
	while (day < k && !PQ.empty()) {

		//*** 밀가루 요청을 할 수 있는 날짜이면서, 
		//동시에 공급받을 수 있는 최댓값을 얻기위한 반복문(정렬로서 만족)
		for (int i = 0;i < PQ.size();i++) { 
			if (PQ[i].first <= day) {
				day += PQ[i].second;
				answer++;
				PQ.erase(PQ.begin()+i);
				break;
			}
		}
	}

	return answer;
}