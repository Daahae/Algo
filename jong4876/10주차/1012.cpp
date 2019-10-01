#define _crt_secure_no_warnings
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int adj[51][51];
int row, col, T, K;

bool isInAdj(int x, int y) { // 배열 범위안 인덱스인지 판단함수
	if (x < 0 || x >= row)
		return false;

	if (y  < 0 || y >= col)
		return false;

	return true;
}

void dfs(int x,int y) {
	adj[x][y] = -1; // 방문 : -1

	for (int i = -1;i <= 1;i++) { // 상하좌우 탐색
		if (isInAdj(x+i, y)) {// 배열 범위안에 존재하고
			if(adj[x+i][y] == 1) // 방문하지 않고 길이 있다면
				dfs(x + i, y);
		}
		if (isInAdj(x, y+i)) {
			if (adj[x][y+i] == 1) 
				dfs(x, y+i);
		}
	}
}


int main() {

	cin >> T;

	for (int z = 0;z < T;z++) {
		int connectionCnt = 0;
		cin >> row >> col >> K;

		//resize
		int N = max(row, col);

		//initialize
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				adj[i][j] = 0;
			}
		}

		for (int i = 0;i < K;i++) {
			int x, y;
			cin >> x >> y;
			adj[x][y] = 1;
		}
		
		//dfs
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				if (adj[i][j] != 1)
					continue;

				dfs(i, j);
				connectionCnt++;
			}
		}
		cout << connectionCnt << endl;
	}


	return 0;
}