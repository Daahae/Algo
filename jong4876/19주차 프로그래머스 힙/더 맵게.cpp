#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	
	priority_queue<int, vector<int>, greater<int>> PQ;//오름차순 우선순위 큐

	for (int i = 0;i < scoville.size();i++)
		PQ.push(scoville[i]);

	while (PQ.top() < K) {
		if (PQ.size() <= 1) {
			answer = -1;
			break;
		}

		int newVal = PQ.top();
		PQ.pop();
		newVal += PQ.top() * 2;
		PQ.pop();

		PQ.push(newVal);
		answer++;
	}



	return answer;
}
