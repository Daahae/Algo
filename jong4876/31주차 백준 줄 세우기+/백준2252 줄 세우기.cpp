#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<queue>

using namespace std;
vector<vector<int>> adj;
vector<int> degree;
int N, M;

void DAG() {

	queue<int> Q;

	// 위상 0 인 점부터 Q에삽입
	for (int i = 1;i <= N;i++) {
		if (degree[i] == 0)
			Q.push(i);
	}

	// 0인 점을 출발지로 해, 도착지의 degree--
	// degree 가 0이 되는 지점을 새로 Queue에 넣고 반복
	while (!Q.empty()) {
		int Qsize = Q.size();

		for (int i = 0;i < Qsize;i++) {
			int st = Q.front();
			cout << st << " ";
			Q.pop();

			for (int &next : adj[st]) {
				degree[next]--;

				if (degree[next] == 0)
					Q.push(next);
			}
		}
	}
}

int main() {
	
	cin >> N >> M;

	degree.resize(N + 1);
	adj.resize(N+1);
	
	for (int i = 0;i < M;i++) {
		int small, big;
		cin >> small >> big;
		
		adj[small].push_back(big);

		// 도착지에 degree++
		degree[big]++;
	}

	// 위상정렬 -> 출발, 시작지가 미정이기 때문
	DAG();
	return 0;
}
