#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 0;
	queue<int> Q;// 다리의 현황
	int sumWeight = 0;
	int i = 0;


	// 큐를 다리처럼 사용해서 시간의 흐름에 따른 큐의 변화를 기록 **
	// 모두 통과하기 까지 걸리는 시간 반환

	while (1) {

		if (i >= truck_weights.size())
			break;

		// 다리가 꽉 차거나 헤더가 끝자락에 도착
		if (Q.size() >= bridge_length) {
			sumWeight -= Q.front();
			Q.pop();
		}


		if (sumWeight+ truck_weights[i] <= weight) {
			Q.push(truck_weights[i]);
			sumWeight += truck_weights[i];
			i++;
		}
		else {
			// 트럭들을 앞으로 진행시키기 = 0삽입
			Q.push(0);
		}
		time++;
	}
	

	// 남아있는 트럭집단 보내버리기
	time += bridge_length;

	return time;
}
