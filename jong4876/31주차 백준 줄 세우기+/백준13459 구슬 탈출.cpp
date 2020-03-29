#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

// 작성한 답안은 Main.cpp로 이름 저장
// 문제마다 파일 1개씩 각각 다른 페이지에 제출

int N, M;
int adj[11][11];
int visited[11][11][11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int aftRx, aftRy;
int aftBx, aftBy;

// 얼마나 멀리 굴러갔는지 카운트
int Rcnt = 0, Bcnt = 0;
int result = 0;
typedef struct _board {
	int Rx;
	int Ry;
	int Bx;
	int By;
	int cnt; // 기울인 횟수
}Board;

// 0: up, 1: down, 2: left, 3: right
void slide(int &Rx, int &Ry, int dir) {

	// 한번 기울인 후 빨공 이동, 0이면 그자리에 세움
	while (adj[Rx+dx[dir]][Ry+dy[dir]] != '#' && adj[Rx][Ry] != '0') {
		Rx += dx[dir];
		Ry += dy[dir];
		Rcnt++;
	}
}


queue<Board> Q;

void BFS() {

	while (!Q.empty()) {

		int cnt = Q.front().cnt;
		if (cnt >= 10)break;

		int Rx = Q.front().Rx;
		int Ry = Q.front().Ry;
		int Bx = Q.front().Bx;
		int By = Q.front().By;
		Q.pop();
		
		// 4방향으로 slide
		for (int i = 0;i < 4;i++) {

			Rcnt = 0, Bcnt = 0;
			slide(Rx, Ry, i);
			slide(Bx, By, i);
			cout << Rx<<" : "<<Ry << endl;
			cout << Bx << " : " << By << endl;

			// 파랑이 먼저 빠진경우 -> 실패
			if (adj[Bx][By] == '0')continue;

			// 빨강이 먼저 빠진경우 -> 성공
			if (adj[Rx][Ry] == '0') {
				result = 1;
				return;
			}
	
			// 같은 위치에 선 경우 -> 이동한 거리에 따라 이전경우로 돌림
			if (Rx == Bx && Ry == By) {
				if (Rcnt > Bcnt) {
					Rx -= dx[i];
					Ry -= dy[i];
				}
				else {
					Bx -= dx[i];
					By -= dy[i];
				}
			}
		
			// 이미 방문한 경우의 수는 큐에 안넣고 넘김
			if (visited[Rx][Ry][Bx][By] == 1) {
				cout << "??" << endl;
				continue;
			}

			Board board = { Rx, Ry, Bx, By, cnt + 1 };
			
			// 다음으로 넘어갈 가치가 있는 board 만 push해놓음
			Q.push(board);
			visited[board.Rx][board.Ry][board.Bx][board.By];

		}
	}
}

int main() {

	cin >> N >> M;
	Board board;
	board.cnt = 0;


	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			char ch;
			cin >> ch;
			adj[i][j] = ch;

			if (ch == 'R') {
				board.Rx = i;
				board.Ry = j;
			
			}
			if (ch == 'B') {
				board.Bx = i;
				board.By = j;
			}
		}
	}

	visited[board.Rx][board.Ry][board.Bx][board.By];
	Q.push(board);
	BFS();
	cout << result;

	return 0;
}
