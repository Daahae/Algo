#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<queue>

#define INF 1000001

using namespace std;

vector <pair<int, int>> adj[1001];
int dp[1001]; // st ~ idx 까지의 최단 경로
int N, M;

int finSt, finEnd;

void printDp() {
	for (int i = 1;i <= N;i++)
		cout << dp[i] << " ";
	cout << endl;

}

void bfs() {
	queue<int> Q;
	priority_queue<pair<int,int>> PQ;
	Q.push(finSt);

	while (!Q.empty()) {
		int Qsize = Q.size();
		
		for (int j = 0;j < Qsize;j++) {
			int st = Q.front();
			Q.pop();

			for (int i = 0;i < adj[st].size();i++) {
			
				int next = adj[st][i].first;
				int nextWeight = adj[st][i].second;

				// 출발 도시에서 st까지의 비용 + st에서 i까지의 비용이 최소인지 확인후 대입
				if (dp[next] > dp[st] + nextWeight ) {
					dp[next] = dp[st] + nextWeight;
					Q.push(next);
				}
			}
			//printDp();
		}
	}
}

void init() {

	for (int i = 1;i <= N;i++) 
		dp[i] = INF;
}

int main() {

	cin >> N >> M;

	init();

	for (int i = 0;i < M;i++) {
		int st, end, weight;
		cin >> st >> end >> weight;

		adj[st].push_back(make_pair(end, weight));
	}

	cin >> finSt >> finEnd;
	dp[finSt] = 0;
	bfs();
	cout << dp[finEnd];


	return 0;
}
