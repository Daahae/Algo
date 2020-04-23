#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int N, M;
int answer;

// 2번쨰에 다시 활성화
int bridgeFlag = 0;
vector<pair<int, int>> Q;

int dirX[2] = { 1, 0};
int dirY[2] = { 0, 1};

bool isGoNext(int adj[10][10], int x, int y) {
	if (x < 0 || x >= N)
		return false;

	if (y < 0 || y >= N)
		return false;

	// 이미 지나온 경로
	if (adj[x][y] == -1)
		return false;

	return true;
}


void DFS(int adj[10][10], int x, int y, int time, int bridgeFlag) {
	if (x == N - 1 && y == N - 1) {
		answer = min(answer, time);
		return;
	}

	// 오작교가 아닌 일반길일 때만 방문체크
	if(adj[x][y] == 1)
		adj[x][y] = -1;

	// 오작교 시간 카운트
	for (int i = 0;i < Q.size();i++) {
		int Qx = Q[i].first;
		int Qy = Q[i].second;

		adj[Qx][Qy]--;
	}

	for (int i = 0;i < 2;i++) {
		int nx = x + dirX[i];
		int ny = y + dirY[i];

		// 배열 인덱스 안에 있는지
		if (isGoNext(adj, nx, ny)) {

			if (adj[nx][ny] >= 1) {
				DFS(adj, nx, ny, time + 1, bridgeFlag);
			}

			// 오작교를 놓을수 있는 경우 -- 여기서부텆 진행
			else if (adj[nx][ny] == 0 && bridgeFlag == 0) {
				bridgeFlag = 1;
				DFS(adj, nx, ny, time + 1, bridgeFlag);
			}
		}
	}
}


int main() {
	int adj[10][10];

	cin >> N>>M;
	answer = N * N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int num;
			cin >> num;
			adj[i][j] = num;
			if (num >= 2)
				Q.push_back(make_pair(i, j));
		}
	}

	DFS(adj, 0, 0,0,0);
	cout << answer;


	return 0;
}
