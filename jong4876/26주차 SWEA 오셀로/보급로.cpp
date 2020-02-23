
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int adj[102][102];
int dp[102][102];
int N;
int destX, destY;

bool isInArr(int x, int y) {
	if (x<1 || x>N)
		return false;

	if (y<1 || y>N)
		return false;

	return true;

}

void bfs() {

	//x,y 좌표
	queue<pair<int, int>> Q;

	// 남 북 동 서
	int dirX[] = { 1,-1,0,0 };
	int dirY[] = { 0,0,1,-1 };

	// (1,1) ~ (N,N)
	Q.push(pair<int, int>(1, 1)); 
	
	// 갈수 있는 모든 방향의 dp갱신
	while (!Q.empty()) {

		int size = Q.size();
	
		int x = Q.front().first;
		int y = Q.front().second;		
		Q.pop();

		for (int j = 0;j < size;j++) {

			for (int i = 0;i < 4;i++) {
				int nextX = x + dirX[i];
				int nextY = y + dirY[i];
				if (isInArr(nextX, nextY)) {
					// 최단거리 계속 갱신하면서 bfs진행
					if (dp[nextX][nextY] > dp[x][y] + adj[nextX][nextY]) {
						dp[nextX][nextY] = dp[x][y] + adj[nextX][nextY];
						
						// 갱신한 경로 = 최단경로 = 이어나갈수 있는 경로 = push
						Q.push(pair<int, int>(nextX, nextY));
					}
				}
			}
		}	
	}
}



int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	
	cin >> T;

	//dp쓰는거 어떨까 -> 상하좌우안됨
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		for (int i = 1;i <= N; i++) {
			string tmp;
			cin >> tmp;
			
			for (int j = 1;j <= N; j++) {
				adj[i][j] = tmp[j-1] - '0';
				dp[i][j] = 9999;
			}
		}

		dp[1][1] = 0;
		// S -> i,j 경로 가중치의 최소값을 dp에 넣기
		bfs();
		cout << "#" << test_case << " " << dp[N][N] << endl;
	}
	return 0;
}