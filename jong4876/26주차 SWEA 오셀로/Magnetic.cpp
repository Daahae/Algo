
#include<iostream>

using namespace std;

int adj[101][101];
int N;

void dfs() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			//N극 자석
			if (adj[i][j] == 1) {

				// 장외인경우
				if (i + 1 > N) {
					adj[i][j] = 0;
				}
				else if(adj[i+1][j] == 0){
					//N 아래로땡기기, 겹치지않게 하기위해 3
					adj[i + 1][j] = 3;
					adj[i][j] = 0;
				}
			}
			//S극 자석
			if (adj[i][j] == 2) {
				if (i - 1 <= 0) {
					adj[i][j] = 0;
				}
				else if (adj[i - 1][j] == 0) {
					//S 위로땡기기
					adj[i - 1][j] = 4;
					adj[i][j] = 0;
				}
			}
		}
	}
}
void makeRightAdj() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (adj[i][j] == 3)
				adj[i][j] = 1;

			if (adj[i][j] == 4)
				adj[i][j] = 2;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// 초당 자석 진행
		cin >> N;


		// 1 : N, 2 : S   상단 N, 하단 S
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				int num;
				cin >> num;
				adj[i][j] = num;
			}
		}

		for (int i = 0;i <= N;i++) {
			dfs();
			makeRightAdj();
		}

		// 교착상태 세기
		int answer = 0;
		for (int i = 1;i <= N;i++) {
			int flag = 0;
			for (int j = 1;j <= N;j++) {
				if (adj[j][i] == 1)
					flag = 1;

				if (adj[j][i] == 2 && flag == 1) {
					answer++;
					flag = 0;
				}
			}
		}

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}