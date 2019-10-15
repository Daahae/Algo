#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int adj[11][11];
int N, M;
int RlocX;
int RlocY;
int BlocX;
int BlocY;
int destX;
int destY;
int firstDir;

int directionFlag = -1; // 1 Left /  2 Right / 3 Up / 4 Down 
int turnCnt = 0;

void getFirstDir() { // 미완
	if (RlocX - destX < 0 && RlocY - destY == 0)
		firstDir = 2;

	else if (RlocX - destX > 0 && RlocY - destY == 0)
		firstDir = 2;

	else if (RlocX - destX < 0 && RlocY - destY == 0)
		firstDir = 2;

	else if (RlocX - destX < 0 && RlocY - destY == 0)
		firstDir = 2;
}



bool isBallInRoad(int x, int y) { // 벽 안넘어가게
	if (adj[x][y] == 1)
		true;

	return false;

}


void DFS(int x, int y) { // 턴할때만 카운트, blue가 빠지는 경우?

	if (turnCnt > 10)
		return;


	if (x == destX && y == destY)
		return;




	if (adj[x][y - 1] == 1 && directionFlag != 1 && directionFlag != 2) { // left, 다시 못돌아가게
		turnCnt++;
		while (adj[x][y - 1] == 1) {
			if (x == destX && y - 1 == destY)
				return;
			y--;
		}

		directionFlag = 1;



		DFS(x, y);
	}

	else if (adj[x][y + 1] == 1 && directionFlag != 1 && directionFlag != 2) { // right
		turnCnt++;
		while (adj[x][y + 1] == 1) {
			if (x == destX && y + 1 == destY)
				return;
			y++;
		}
		directionFlag = 2;
		DFS(x, y);
	}

	else if (adj[x - 1][y] == 1 && directionFlag != 3 && directionFlag != 4) { // up
		turnCnt++;
		while (adj[x - 1][y] == 1) {
			if (x - 1 == destX && y == destY)
				return;
			x--;
		}

		directionFlag = 3;
		DFS(x, y);
	}

	else if (adj[x + 1][y] == 1 && directionFlag != 3 && directionFlag != 4) { // down
		turnCnt++;
		while (adj[x + 1][y] == 1) {
			if (x + 1 == destX && y == destY)
				return;
			x++;
		}
		directionFlag = 4;
		DFS(x, y);
	}



}


int main() {

	cin >> N >> M;

	for (int i = 0;i < N;i++) { // 세팅
		for (int j = 0;j < M;j++) {
			char tmp;

			cin >> tmp;

			if (tmp == '#')
				adj[i][j] = 0; // 벽

			else if (tmp == '.')
				adj[i][j] = 1; // 경로

			else if (tmp == 'R') {
				RlocX = i;
				RlocY = j;
				adj[i][j] = 0;
			}
			else if (tmp == 'B') {
				BlocX = i;
				BlocY = j;
				adj[i][j] = 0;
			}
			else if (tmp == 'O') {
				destX = i;
				destY = j;
				adj[i][j] = 1;
			}
		}
	}

	DFS(RlocX, RlocY);
	cout << turnCnt << endl;
}