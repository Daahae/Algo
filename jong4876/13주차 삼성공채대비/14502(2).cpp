#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
int N, M;
int adj[8][8];
int tmpAdj[8][8];
int spreadAdj[8][8];
vector<pair<int ,int>> virusLoc;

int maxSafeArea = 0; // 전염안된 위치 카운트

void copy(int A[8][8], int B[8][8]) {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			A[i][j] = B[i][j];
		}
	}
}

void printArr(int arr[8][8]) {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isGoNext(int x, int y) {
	if (x < 0 || x >= N)
		return false;

	if (y < 0 || y >= M)
		return false;

	if (spreadAdj[x][y] != 0)
		return false;

	return true;
	

}

void BFS() {
	
	copy(spreadAdj, tmpAdj);
	queue<pair<int,int>> Q;

	for (int i = 0;i < virusLoc.size();i++) { // 초기 큐 삽입
		Q.push(pair<int, int >(virusLoc[i].first, virusLoc[i].second));
	}

	while (!Q.empty()) {
		int size = Q.size();

		for (int i = 0;i < size;i++) {
			int x = Q.front().first;
			int y = Q.front().second;

			if (isGoNext(x - 1,y)) {
				spreadAdj[x - 1][y] = 2;
				Q.push(pair<int, int>(x - 1, y));
			}
			if (isGoNext(x + 1, y)) {
				spreadAdj[x + 1][y] = 2;
				Q.push(pair<int, int>(x + 1, y));
			}
			if (isGoNext(x, y-1)) {
				spreadAdj[x][y-1] = 2;
				Q.push(pair<int, int>(x, y -  1));
			}
			if (isGoNext(x, y+1)) {
				spreadAdj[x][y+1] = 2;
				Q.push(pair<int, int>(x, y + 1));
			}
			Q.pop();
		}
	}

	int safeArea = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (spreadAdj[i][j] == 0) {
				safeArea++;
			}
		}
	}
	maxSafeArea = max(maxSafeArea, safeArea);

}


void make23Pillar(int pillarCnt) {

	if (pillarCnt == 3) {// 기둥의 수 3개가 될 때
		BFS();
		return;
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (tmpAdj[i][j] == 0) {
				tmpAdj[i][j] = 1;
				make23Pillar(pillarCnt+1);
				tmpAdj[i][j] = 0;
			}
		}
	}
}



int main() {

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> adj[i][j];
			if (adj[i][j] == 2)
				virusLoc.push_back(pair<int, int>(i, j));
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			copy(tmpAdj, adj);
		//	printArr(tmpAdj);

			if (tmpAdj[i][j] == 0) {
				tmpAdj[i][j] = 1;
				make23Pillar(1);
				tmpAdj[i][j] = 0;
			}
		}
	}

	cout << maxSafeArea;

	return 0;
}