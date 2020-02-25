#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int adj[1001][1001];
int cnt = 0;
int row, col;
queue<pair<int,int>> Q;

bool isInArr(int x, int y) {

	if (x < 1 || x > row)
		return false;

	if (y < 1 || y > col)
		return false;

	if (adj[x][y] == -1 || adj[x][y] == 1)
		return false;

	return true;

}

// 정통 bfs
void bfs() {
	int dirX[4] = { 0,0,-1,1 };
	int dirY[4] = { 1,-1,0,0 };

	while (!Q.empty()) {
		int Qsize = Q.size();

		for (int k = 0;k < Qsize;k++) {
			int x = Q.front().first;
			int y = Q.front().second;

			Q.pop();

			for (int i = 0;i < 4;i++) {
				int nextX = x + dirX[i];
				int nextY = y + dirY[i];
				if (isInArr(nextX, nextY)) {
					adj[nextX][nextY] = 1;
					Q.push(pair<int, int>(nextX, nextY));
				}
			}			
		}
		cnt++;
	}
}
int main() {
	cin >> col>> row;
	
	for (int i = 1;i <= row;i++) {
		for (int j = 1;j <= col;j++) {
			int tmp;
			cin >> tmp;
			adj[i][j] = tmp;
			if (tmp == 1)
				Q.push(pair<int, int>(i, j));

		}
	}
	bfs();

	for (int i = 1;i <= row;i++) {
		for (int j = 1;j <= col;j++) {
			if (adj[i][j] == 0)
				cnt = 0;
		}
	}
	cout << cnt-1;
	return 0;
}