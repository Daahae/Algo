#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> answer;
int visited[10000]; // 미방문 0, 방문 1


void clearVisited(int size) {
	for (int i = 0;i < size;i++)
		visited[i] = 0;
}


void DFS(int startIdx, vector<vector<string>> tickets) {

	int destIdx = -1;

	answer.push_back(tickets[startIdx][1]);
	visited[startIdx] = 1;

	for (int i = 0;i<tickets.size();i++) {
		// 도착지 ==> 출발지
		if (tickets[startIdx][1].compare(tickets[i][0]) == 0
			&& visited[i] == 0) {

			destIdx = i;
			DFS(destIdx, tickets);
		}
	}

	// 더 나아갈 경로가 없다면
	if (destIdx == -1) {

		// 다 돌지 못했다면
		if (answer.size() < tickets.size() + 1) {

			// 이전 값을 롤백,	 방문체크 취소
			answer.pop_back();
			visited[startIdx] = 0;
		}
	}

}


//DFS 스택기반?
vector<string> solution(vector<vector<string>> tickets) {

	int startIdx;
	int size = tickets.size();


	sort(tickets.begin(), tickets.end());

	// 모든 인덱스에 대해서 DFS가 도는 지 확인
	for (int i = 0;i < tickets.size();i++) {

		if (tickets[i][0].compare("ICN") == 0) {
			answer.clear();
			clearVisited(size);
			answer.push_back(tickets[i][0]);
			startIdx = i;

			DFS(startIdx, tickets);
			if (answer.size() == tickets.size() + 1)
				return answer;
		}
	}
	//answer.clear();
	return answer;
}
