#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int adjArr[101][101];
int heightArr[101][101];
int N;
int rain;
int safeAreaCnt = 0;
int maxSafeAreaCnt = -1;

bool isInArr(int x, int y) {
	if (x < 0 || x >= N)
		return false;

	if (y < 0 || y >= N)
		return false;

	return true;

}


void dfs(int x, int y) {

	adjArr[x][y] = -1; // 방문체크

	for (int i = -1;i <= 1;i++) {
		if (isInArr(x + i, y)) {
			if (adjArr[x + i][y] == 1) {
				dfs(x + i, y);
			}
		}
	}

	for (int i = -1;i <= 1;i++) {
		if (isInArr(x, y+i)) {
			if (adjArr[x][y+i] == 1) {
				dfs(x, y+i);
			}
		}
	}
	

}


int main() {

	cin >> N;


	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int tmp;
			cin >> tmp;
			heightArr[i][j] = tmp;
		}
	}

	
	for (int rain = 1;rain <= 100;rain++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				int tmp;
				tmp = heightArr[i][j];
				if (tmp >= rain) // 문제
					adjArr[i][j] = 1;

				else
					adjArr[i][j] = 0;
			}
		}


		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (adjArr[i][j] != 1)
					continue;

				safeAreaCnt++;
				dfs(i, j);
			}
		}
		if (safeAreaCnt > maxSafeAreaCnt)
			maxSafeAreaCnt = safeAreaCnt;


		safeAreaCnt = 0;

	}

	cout << maxSafeAreaCnt << endl;

	

	return 0;
}