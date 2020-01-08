#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 0;
	queue<int> Q;
	int sum = 0;

	Q.push(truck_weights[0]);

	for (int i = 0;i < truck_weights.size();i++) {
		
		if (sum + truck_weights[i] <= weight) {
			sum += truck_weights[i];
			Q.push(truck_weights[i]);
			time++;
		}
		else {
			while (sum + truck_weights[i] > weight) {
				sum -= Q.front();
				Q.pop();
			}
			Q.push(truck_weights[i]);
			sum += truck_weights[i];
			time += bridge_length;
		}
	}

	// 큐가 넘치지 않았다면, 그대로 다리를 통과
	time += bridge_length;


	return time;
}