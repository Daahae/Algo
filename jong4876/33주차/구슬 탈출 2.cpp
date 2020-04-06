#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int N, M;
char adj[11][11];
char visited[11][11][11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int result = 0;
typedef struct _board {
	int Rx;
	int Ry;
	int Bx;
	int By;
	int cnt; // 기울인 횟수
}Board;

// 0: up, 1: down, 2: left, 3: right
void slide(int &x, int &y, int &cnt, int dir) {
	// 한번 기울인 후 빨공 이동, O이면 그자리에 세움
	while (adj[x + dx[dir]][y + dy[dir]] != '#' && adj[x][y] != 'O') {
		x += dx[dir];
		y += dy[dir];
		cnt++;
	}
	
}

void printBoard(int Rx, int Ry, int Bx, int By) {

	for (int i = 0;i < N;i++) {
		for (int j = 0; j < M;j++) {
			if(i==Rx && j==Ry)
				cout << "R";

			else if (i == Bx && j == By)
				cout << "B";

			else
				cout << adj[i][j];
		}
		cout << endl;
	}
	cout << endl;

}

queue<Board> Q;

void BFS() {

	while (!Q.empty()) {

		// cnt -> 기울이기를 실행한 횟수
		int cnt = Q.front().cnt;
		if (cnt >= 10)break;

		int Rx = Q.front().Rx;
		int Ry = Q.front().Ry;
		int Bx = Q.front().Bx;
		int By = Q.front().By;
		Q.pop();
		
		// 4방향으로 slide
		for (int i = 0;i < 4;i++) {
			int Rcnt = 0, Bcnt = 0;
			int nextRx = Rx, nextRy = Ry;
			int nextBx = Bx, nextBy = By;
	
			//printBoard(Rx, Ry, Bx, By);
			slide(nextRx, nextRy, Rcnt, i);
			slide(nextBx, nextBy, Bcnt, i);
			//printBoard(nextRx, nextRy, nextBx, nextBy);

			// 파랑이 먼저 빠진경우 -> 실패
			if (adj[Bx][By] == 'O') continue;
			

			// 빨강이 먼저 빠진경우 -> 성공
			if (adj[Rx][Ry] == 'O') {
				result = cnt;
				return;
			}
	
			// 같은 위치에 선 경우 -> 이동해온 방향의 이전경우로 돌림
			if (nextRx == nextBx && nextRy == nextBy) {
				if (Rcnt > Bcnt) {
					nextRx -= dx[i];
					nextRy -= dy[i];
				}
				else {
					nextBx -= dx[i];
					nextBy -= dy[i];
				}
			}
		
			// 이미 방문한 경우의 수는 큐에 안넣고 넘김 (빨공 파공 방문 여부체크)
			if (visited[nextRx][nextRy][nextBx][nextBy] == 1) continue;
			Board board = { nextRx, nextRy, nextBx, nextBy, cnt + 1 };
			
			// 다음으로 넘어갈 가치가 있는 board 만 push해놓음
			Q.push(board);

			// 빨공 파공 방문체크
			visited[board.Rx][board.Ry][board.Bx][board.By] = 1;
		}
		result = -1;
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
				adj[i][j] = '.';
			}
			if (ch == 'B') {
				board.Bx = i;
				board.By = j;
				adj[i][j] = '.';
			}
		}
	}

	// 빨간공 파란공 위치 방문체크
	visited[board.Rx][board.Ry][board.Bx][board.By] = 1;
	Q.push(board);
	BFS();
	cout << result;

	return 0;
}
