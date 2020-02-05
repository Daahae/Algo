
#include<iostream>
#include<algorithm>

using namespace std;

int adj[11][11];
int queenCnt;
int answer;


// 해당 위치가 퀸을 놓을 수 있는 장소이면 두고 아니면 안둠
bool isLocateQueen(int x, int y, int N) { 
	
	// 행,열 판별
	for (int i = 0;i < N;i++) {
		if (adj[x][i] == 1)
			return false;

		if (adj[i][y] == 1)
			return false;
	}

	// 왼쪽 대각선 판별
	int max = x > y ? x : y;
	
	for (int i = 1;i <= max;i++) {
		if (adj[x - i][y - i] == 1) 
			return false;
		
		if (adj[x - i][y + i] == 1) 
			return false;
		
	}
	return true;
}
void printAdj(int N) {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// 배열 복사, x는 반복을 줄이고자 함
void copyAdj(int A[11][11], int B[11][11],int x, int N) { 
	
	for (int i = x+1;i < N;i++) {
		for (int j = 0;j < N;j++) {
			A[i][j] = B[i][j];
		}
	}
}


void dfs(int x, int y,int N, int cnt) {
	int tmpAdj[11][11]; // 원상복구용 배열
	adj[x][y] = 1;
	if (cnt >= queenCnt) {
		printAdj(N);
		answer++;
		return;
	}

	for (int i = x+1;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (isLocateQueen(i, j, N)) {
				copyAdj(tmpAdj, adj,x, N);
				dfs(i, j, N, cnt + 1);
				copyAdj(adj, tmpAdj,x, N); // 원상 복구
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
	
		cin >> N;

		// 초기화
		answer = 0;
		queenCnt = N; // 퀸을 놓을 수 있는 갯수
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				adj[i][j] = 0;
			}
		}

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (isLocateQueen(i, j, N)) {
					dfs(i, j, N, 1);
					adj[i][j] = 0;// 원상 복구
				}
			}
		}
		
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}