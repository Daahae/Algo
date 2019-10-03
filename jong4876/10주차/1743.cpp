#define _crt_secure_no_warnings
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int adj[100][100];
int N, M;
int cnt = 0, maxCnt = 0;

bool isInArr(int i,int j) { // 유효한 인덱스인지

	if (i <= 0 || i > N)
		return false;

	if (j <= 0 || j > M)
		return false;

	return true;
}


void dfs(int x, int y) {

	adj[x][y] = -1; // 방문표시
	cnt++;

	for(int i=-1;i<=1;i++){
		if (isInArr(x + i, y)) {
			if (adj[x + i][y] == 1) { // 유효한 길이면
				dfs(x + i, y);
			}
		}
		if (isInArr(x, y+i)) {
			if (adj[x][y+i] == 1) { // 유효한 길이면
				dfs(x, y+i);
			}
		}
	}
}



int main() {
	int K;
	cin >> N>>M>>K;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			adj[i][j] = 0;
		}
	}


	for (int i = 0;i < K;i++) {
		int x, y;
		cin >> x >> y;
		adj[x][y] = 1;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cnt = 0;
			if (adj[i][j] != 1)
				continue;

			dfs(i,j);
			if (maxCnt < cnt) {
				maxCnt = cnt;
			}
		}
	}
	cout << maxCnt << endl;



	return 0;
}