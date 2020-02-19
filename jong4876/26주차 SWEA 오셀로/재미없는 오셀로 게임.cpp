
#include<iostream>

using namespace std;
int adj[10][10]; // 4,6,8
int N,M;

void dfs(int x, int y) {

	int present = adj[x][y];

	//동
	for (int i = y-1; i >= 1;i--) {

		//바꿔야할 타이밍
		if (adj[x][i] == present) {
			for (int j = y;j >= i;j--) {
				adj[x][j] = present;
			}
			break;
		}
		else if (adj[x][i] == 0)
			break;
	}

	//서
	for (int i = y+1; i <= N;i++) {

		if (adj[x][i] == present) {
			for (int j = y;j <= i; j++) {
				adj[x][j] = present;
			}
			break;
		}
		else if (adj[x][i] == 0)
			break;
	}

	//북
	for (int i = x-1; i >= 1;i--) {
		if (adj[i][y] == present) {
			for (int j = x;j >= i;j--) {
				adj[j][y] = present;
			}
			break;
		}
		else if (adj[i][y] == 0)
			break;
	}



	//남
	for (int i = x+1; i <= N;i++) {
		if (adj[i][y] == present) {
			for (int j = x;j <= i; j++) {
				adj[j][y] = present;
			}
			break;
		}
		else if (adj[i][y] == 0)
			break;
	}

	/// 대각선

	//왼위 대각선
	int cnt = 1;
	while (x-cnt >=0 && y-cnt >=0) {

		if (adj[x - cnt][y - cnt] == 0)
			break;

		if (adj[x - cnt][y - cnt] == present) {
			for (int i = 1;i <= cnt;i++)
				adj[x - i][y - i] = present;
			break;
		}
		cnt++;
	}

	//오른 아래 대각선
	cnt = 1;
	while (x + cnt <= N && y + cnt <= N) {

		if (adj[x + cnt][y + cnt] == 0)
			break;

		if (adj[x + cnt][y + cnt] == present) {
			for (int i = 1;i <= cnt;i++)
				adj[x + i][y + i] = present;
			break;
		}
		cnt++;
	}


	//오른위 대각선
	cnt = 1;
	while (x - cnt >= 0 && y + cnt <= N) {

		if (adj[x - cnt][y + cnt] == 0)
			break;

		if (adj[x - cnt][y + cnt] == present) {
			for (int i = 1;i <= cnt;i++)
				adj[x - i][y + i] = present;
			break;
		}
		cnt++;
	}

	//왼 아래 대각선
	cnt = 1;
	while (x + cnt <= N && y - cnt >= 0) {

		if (adj[x + cnt][y - cnt] == 0)
			break;

		if (adj[x + cnt][y - cnt] == present) {
			for (int i = 1;i <= cnt;i++)
				adj[x + i][y - i] = present;
			break;
		}
		cnt++;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
	
		//1흑, 0빈공간, 2백

		cin >> N >> M;

		//초기화
		for (int i = 1;i <= 8;i++) {
			for (int j = 1;j <= 8;j++) {
				adj[i][j] = 0;
			}
		}

		// 기본 배치
		adj[N / 2][N / 2] = 2;
		adj[N / 2 + 1][N / 2] = 1;
		adj[N / 2][N / 2 + 1] = 1;
		adj[N / 2 + 1][N / 2 + 1] = 2;


		for (int i = 0;i < M;i++) {
			int x, y, stone;

			cin >> x >> y >> stone;
			adj[x][y] = stone;

			// x,y 기준으로 자신의 돌로바꾸기
			dfs(x,y);
		}

		int black = 0, white = 0;
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (adj[i][j] == 1)
					black++;
				else if (adj[i][j] == 2)
					white++;
			}
		}
		cout << "#"<<test_case<<" " << black << " " << white<<endl;
	}
	return 0;
}