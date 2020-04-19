#include<iostream>
#include<algorithm>
#include<queue>
#include<stdio.h>

using namespace std;
int visited[31][31];

// 확률계산을 위한 배열
int actionCnt;
double answer;

// EWSN 나올확률
double dirPercent[4];

// EWSN 순서
int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { 1,-1,0,0 };

void DFS(int x, int y, double nowPercent, int cnt) {

	if (cnt == 0)
		return;

	visited[x][y] = 1;

	// 동서남북 확률을 곱해가며 재귀
	for (int i = 0;i < 4;i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		// 단순하지 않은 경우 = 이미 지나간 곳 방문
		if (visited[nextX][nextY] == 1) {
			answer += nowPercent * dirPercent[i];
			continue;
		}
		else {
			DFS(nextX, nextY,nowPercent*dirPercent[i],cnt-1);
			
			// 경로 사용 후 원상복구
			visited[nextX][nextY] = 0; 
		}
	}		
}


int main() {	
	cin >> actionCnt;
	for (int i = 0;i < 4;i++) {
		double per;
		cin >> per;
		dirPercent[i] = per / 100.0;
	}
	
	//start = (15,15)
	DFS(15,15,1.0, actionCnt);

	// 소수점 10자리 **
	cout.precision(10);
	cout<<fixed << 1.0 - answer << endl;

	return 0;
}
