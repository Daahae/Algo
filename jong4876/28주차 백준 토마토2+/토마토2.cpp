#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int adj[101][101][101];
int cnt = 0;
int row, col, height;
queue<pair<int, int>> Q;
queue<int> Qz; // 별도로 관리

// 배열밖을 벗어나는지, 벽이있는지, 이미 익은 토마토인지 체크
bool isInArr(int x, int y, int z) {

	if (x < 1 || x > row)
		return false;

	if (y < 1 || y > col)
		return false;

	if (z < 1 || z > height)
		return false;

	if (adj[x][y][z] == 1 || adj[x][y][z] == -1)
		return false;


	return true;

}

// 토마토 익히기
void bfs() {
	int dirX[6] = { 0,0,-1,1,0,0 };
	int dirY[6] = { 1,-1,0,0,0,0 };
	int dirZ[6] = { 0,0,0,0,1,-1 };

	while (!Q.empty()) {
		int Qsize = Q.size();

		for (int k = 0;k < Qsize;k++) {
			int x = Q.front().first;
			int y = Q.front().second;
			int z = Qz.front();

			Q.pop();
			Qz.pop();

			for (int i = 0;i < 6;i++) {
				int nextX = x + dirX[i];
				int nextY = y + dirY[i];
				int nextZ = z + dirZ[i];
				if (isInArr(nextX, nextY, nextZ)) {
					adj[nextX][nextY][nextZ] = 1;
					Q.push(pair<int, int>(nextX, nextY));
					Qz.push(nextZ);
				}
			}
		}
		cnt++;
	}
}
int main() {
	cin >> col >> row >> height;

	// height 인덱스는 별도의 Queue로 관리
	for (int k = 1;k <= height;k++) {
		for (int i = 1;i <= row;i++) {
			for (int j = 1;j <= col;j++) {
				int tmp;
				cin >> tmp;
				adj[i][j][k] = tmp;
				if (tmp == 1) {
					Q.push(pair<int, int>(i, j));
					Qz.push(k);
				}
			}
		}
	}
	bfs();

	// 안익은게 없는지 확인
	for (int i = 1;i <= row;i++) {
		for (int j = 1;j <= col;j++) {
			for (int k = 1;k <= height;k++) {
				if (adj[i][j][k] == 0)
					cnt = 0;
			}
		}
	}
	cout << cnt - 1;
	return 0;
}