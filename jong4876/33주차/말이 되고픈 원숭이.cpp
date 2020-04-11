#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int K, W, H;
int adj[201][201];
int dp[201][201];
int minRoute;
int isArriveFlag = 0;

int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };

int dirHorseX[8] = {2, 2,-2,-2,1,1,-1,-1};
int dirHorseY[8] = {1,-1, 1,-1,2,-2,2,-2};

bool isGoNext(int x, int y) {
	if (adj[x][y] == 1)
		return false;
		
	if (x < 0 || y < 0)
		return false;

	if (x >= W || y >= H)
		return false;

	return true;
}


void DFS(int x, int y, int routeCnt) {

	if ((x == W - 1) && (y == H - 1)) {
		isArriveFlag = 1;
		minRoute = min(minRoute, routeCnt);
		return;
	}

	// 더많은 비용 소모되는 재귀는 더이상 진행할필요없음
	if (dp[x][y] < routeCnt) 
		return;
	

	dp[x][y] = routeCnt;
	adj[x][y] = 1;


	for (int i = 0;i < 4;i++) {
		// 원숭이 걸음
		if (isGoNext(x + dirX[i], y + dirY[i])  ) {
			DFS(x + dirX[i], y + dirY[i], routeCnt + 1);
			adj[x + dirX[i]][y + dirY[i]] = 0;
		}
	}

	if (K > 0) {
		for (int i = 0;i < 4;i++) {
			// 말 걸음
			if (isGoNext(x + dirHorseX[i], y + dirHorseY[i])) {
				K--;
				DFS(x + dirHorseX[i], y + dirHorseY[i], routeCnt + 1);
				adj[x + dirHorseX[i]][y + dirHorseY[i]] = 0;
				K++;
			}
		}
	}
}


// K : 말처럼 움직일 수 있는횟수, W : 가로, H : 세로

int main() {

	cin >> K;
	cin >> W >> H;

	for (int i = 0;i < W;i++) {
		for (int j = 0;j < H;j++) {
			cin >> adj[i][j];	
			dp[i][j] = W * H;
		}
	}

	minRoute = W * H;
	DFS(0,0,0);

	if(isArriveFlag == 1)
		cout << minRoute << endl;

	else cout << -1;
	
	return 0;
}
