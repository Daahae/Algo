#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
int N, L, K;
int adj[101][101];
map<int, char> directionMap; // 빈 키의 값은 false
int cnt = 0;
int tailCnt = 0;

bool apple = false;
queue<pair<int, int>> Q;


// 1 left, 2 right, 3 up, 4 down
bool isInArr(int x, int y) {
	if (x<1 || x > N)
		return false;

	if (y<1 || y > N)
		return false;

	return true;
}
void tailMove() {
	int tailX = Q.front().first;
	int tailY = Q.front().second;

	adj[tailX][tailY] = 0; //꼬리가 지나간 길은 일반 길로
	Q.pop();
	
}

void printAdj() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cout << adj[i][j] << "  ";
		}
		cout << endl;
	}
	cout << cnt << endl;
	cout << endl;
}
int firstFlag = 1; // 처음 한턴 쉼

void DFS(int x, int y, int direction) {

	
	// 자기몸에박음
	if (adj[x][y] == -1)
		return;


	// 사과위치 1, 뱀이 걸친위치 -1
	// 사과위치 체크
	if (adj[x][y] == 1)
		apple = true;

	// 뱀 머리 이동경로 체크, 이동했던 경로에 삽입
	adj[x][y] = -1;
	Q.push(pair<int, int>(x, y));
	//printAdj();

	// 꼬리가 한칸 씩 쫓아옴 (-1이 있는 방향으로)
	// 사과를 먹으면 꼬리 한번 안쫒아옴
	if (apple || firstFlag == 1) {
		apple = false;
		firstFlag = 0;
	}
	else
		tailMove();


	// 벽에 박음
	if (!isInArr(x, y))
		return;



	// 90도 턴함
	if (directionMap[cnt] != false) {
		if (directionMap[cnt] == 'D') { // 오른쪽 턴
			if (direction == 1)
				direction = 3;

			else if (direction == 2)
				direction = 4;

			else if (direction == 3)
				direction = 2;

			else if (direction == 4)
				direction = 1;
		}
		else { // L 왼쪽 턴
			if (direction == 1)
				direction = 4;

			else if (direction == 2)
				direction = 3;

			else if (direction == 3)
				direction = 1;

			else if (direction == 4)
				direction = 2;
		}
	}


	// 재귀로 진행
	if (direction == 1) {
		y--;
		cnt++;
		DFS(x, y, 1);
	}

	else if (direction == 2) {
		y++;
		cnt++;
		DFS(x, y, 2);
	}

	else if (direction == 3) {
		x--;
		cnt++;
		DFS(x, y, 3);
	}

	else if (direction == 4) {
		x++;
		cnt++;
		DFS(x, y, 4);
	}



}


int main() {
	cin >> N;
	cin >> K;
	for (int i = 0;i < K;i++) {
		int x, y;//사과위치
		cin >> x >> y;
		adj[x][y] = 1;
	}
	cin >> L;
	for (int i = 0;i < L;i++) {
		//D 오른쪽 L 왼쪽
		int sec;
		char direction;
		cin >> sec >> direction;
		directionMap[sec] = direction;
	}

	DFS(1, 1, 2); // 1행1열에서 오른쪽방향으로 시작

	cout << cnt;
	return 0;

}
