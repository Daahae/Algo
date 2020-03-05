#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>> adj;
vector<int> building, dp, deg;

int T, N, K;
int W;

void init() {
	building.clear();
	dp.clear();
	adj.clear();
	deg.clear();

	building.resize(N + 1);
	dp.resize(N + 1);
	adj.resize(N + 1);
	deg.resize(N + 1);
}

// end -> st
void BFS() {

	queue<int> Q;

	// 0인 차수부터 시작, DP 갱신
	for (int i = 1;i <= N;i++) {
		if (deg[i] == 0) {
			Q.push(i);
			dp[i] = building[i];
		}
	}

	int flag = 0;
	while (!Q.empty()) {
		int Qsize = Q.size();

		if (flag == 1)
			break;

		for (int i = 0;i < Qsize;i++) {
			int st = Q.front();
		
			Q.pop();

			// 진행하면서 degre -- 
			for (int &end : adj[st]) {
				deg[end]--;

				// 위상 0이면 다음 st지점 -> Q삽입
				if (deg[end] == 0)
					Q.push(end);
				
				// dp[next]에 도달하는 더 오래걸리는 시간으로 갱신
				if (dp[end] < building[end] + dp[st]) 
					dp[end] = building[end] + dp[st];
					
			}
		}
	}
}

int main() {

	cin >> T;

	for (int test_case = 0;test_case < T;test_case++) {
		
		cin >> N >> K;
	
		init();
		for (int i = 1;i <= N;i++) 
			cin >> building[i];
		

		
		for (int i = 0;i < K;i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			
			// 도달하는 간선에 대한 degree++
			deg[v]++;
		}
		
		cin >> W;
		

		// 시작지점, 끝지점 없음 -> 위상정렬
		BFS();

		cout << dp[W] << endl;
	}

	return 0;
}