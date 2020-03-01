#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int N;
vector<vector<long long>> adj;
vector<pair<long long, long long>> line;
int level = 0;


// i, j가 친구인지
bool isFriend(int i, int j) {
	
	if (line[i].second < line[j].first)
		return false;

	if (line[i].first > line[j].second)
		return false;

	return true;
}


int main() {

	cin >> N;
	line.push_back(pair<long long, long long>(0, 0)); // 0 번째 line은 비워놓기

	for (int i = 1;i <= N;i++) {
		long long left, right;
		cin >> left >> right;
		line.push_back(pair<long long, long long>(left, right));	
	}

	adj.resize(301);

	for (int i = 0;i <= N;i++) {
		adj[i].resize(301);
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			adj[i][j] = 9999;
		}
	}

	// 1차친구 정보저장
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (isFriend(i, j) && i!=j) {
				adj[i][j] = 1;
				adj[j][i] = 1;
			}
		}
	}

	// 2+ 차 가능한 친구 저장
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			for (int k = 1;k <= N;k++) {
				if (adj[i][k] > adj[i][j] + adj[j][k])
					adj[i][k] = adj[i][j] + adj[j][k];
			}
		}
	}


	int Q;
	cin >> Q;

	for (int i = 0;i < Q;i++) {
		int start, end;
		cin >> start >> end;

		if(adj[start][end] == 9999)
			cout << -1 << endl;
		else
			cout << adj[start][end] << endl;
	}

	
	return 0;
}