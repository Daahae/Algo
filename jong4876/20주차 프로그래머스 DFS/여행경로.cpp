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
		// 도착지 ==> 출발지, 방문한 적 없다면
		if (tickets[startIdx][1].compare(tickets[i][0]) == 0
			&& visited[i] == 0) {

			destIdx = i;
			DFS(destIdx, tickets);
			break;
		}
	}
}


//DFS 스택기반?
vector<string> solution(vector<vector<string>> tickets) {

	int startIdx;
	int size = tickets.size();
	vector<vector<string>> route;

	// 모든 인덱스에 대해서 DFS가 도는 지 확인
	for (int i = 0;i < tickets.size();i++) {

		if (tickets[i][0].compare("ICN") == 0) {
			answer.clear();
			clearVisited(size);
			answer.push_back(tickets[i][0]);
			startIdx = i;

			DFS(startIdx, tickets);
			if (answer.size() == tickets.size() + 1) {
				route.push_back(answer);
			}
		}
	}
	//cout << route.size();

	sort(route.begin(), route.end());


	//answer.clear();
	return route[0];
}
