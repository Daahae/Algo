#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> answer;
int visited[10000];


void clearVisited( int size) {
	for (int i = 0;i < size;i++)
		visited[i] = 0;
}

void printVec() {
	for (int i = 0;i < answer.size();i++)
		cout << answer[i] << " ";

	cout << endl;
}


void DFS(int startIdx, vector<vector<string>> tickets) {

	int destIdx = -1;
	string destAirport = "ZZZ";

	if (answer.size() >= tickets.size()+1) {
		return;
	}

	
	answer.push_back(tickets[startIdx][1]);
	visited[startIdx] = 1;

	for(int i=0;i<tickets.size();i++){
		// 도착지 ==> 출발지
		if (tickets[startIdx][1].compare(tickets[i][0]) == 0
			&& visited[i]==0 ) {
			
			// 사전순 체크
			if (destAirport.compare(tickets[i][1]) > 0) {
				destAirport = tickets[i][1];
				destIdx = i;
			}
		}
	}

	// 사전순 제일 이른 것으로 재귀
	if(destIdx !=-1)
		DFS(destIdx, tickets);
}


//DFS 스택기반?
vector<string> solution(vector<vector<string>> tickets) {

	int startIdx;
	int size = tickets.size();


	sort(tickets.begin(), tickets.end());

	// 모든 인덱스에 대해서 DFS가 도는 지 확인?
	for (int i = 0;i < tickets.size();i++) {
		answer.clear();
		clearVisited(size);
		
		if (tickets[i][0].compare("ICN") == 0) {
			answer.push_back("ICN");
			startIdx = i;
			DFS(startIdx, tickets);
			if (answer.size() == tickets.size() + 1)
				return answer;
		}
	}

	return answer;
}