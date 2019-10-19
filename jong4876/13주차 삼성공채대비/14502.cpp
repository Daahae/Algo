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

bool isInArr(int x, int y) {
	if (x < 0 || x >= N)
		return false;
	if (y < 0 || y >= M)
		return false;

	return true;

}

void DFSforFillVirus(int x, int y) { // 2가있는 곳부터 시작해서 방안에 바이러스 퍼트리기
	spreadAdj[x][y] = 2;

	if (isInArr(x - 1, y)) {
		if (spreadAdj[x - 1][y] == 0 ) {
			DFSforFillVirus(x - 1, y);
		}
	}
	if (isInArr(x + 1, y)) {
		if (spreadAdj[x + 1][y] == 0)
			DFSforFillVirus(x + 1, y);
	}

	if (isInArr(x, y-1)) {
		if (spreadAdj[x][y-1] == 0)
			DFSforFillVirus(x, y-1);
	}

	if (isInArr(x, y+1)) {
		if (spreadAdj[x][y+1] == 0)
			DFSforFillVirus(x, y+1);
	}

}

void fillVirus() {

	copy(spreadAdj,tmpAdj); // 새로운 행렬사용

	for (int i = 0;i < virusLoc.size();i++) {
		DFSforFillVirus(virusLoc[i].first, virusLoc[i].second);
	}

}



void makeWall(int cnt) {
	if (cnt == 3) { // 벽을 3개 다 박았다면
		fillVirus();
		int safeArea = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (spreadAdj[i][j] == 0)
					safeArea++;
			}
		}
	
	
		maxSafeArea = max(maxSafeArea, safeArea);
		return;
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (tmpAdj[i][j] == 0) {
				tmpAdj[i][j] = 1;
				makeWall(cnt + 1);
				tmpAdj[i][j] = 0; // 다시 원상복귀
			}
		}
	}


}

int main() {

	cin >> N >> M;

	for (int i = 0;i < N;i++) { // 벽 3개세우는 모든 경우를 생각?
		for (int j = 0;j < M;j++) {
			int tmp;
			cin >> tmp;
			adj[i][j] = tmp;
			tmpAdj[i][j] = tmp;

			if (tmp == 2)
				virusLoc.push_back(pair<int, int>(i, j));// 바이러스 위치 저장
		}
	}


	
	for (int i = 0;i < N;i++) { // make wall
		for (int j = 0;j < M;j++) {
			if (adj[i][j] == 0) {
				copy(tmpAdj, adj); // 첫번째 벽의 이동때는 copy

				tmpAdj[i][j] = 1;
				makeWall(1);
				tmpAdj[i][j] = 0;
			}

		}
	}
	

	cout << maxSafeArea;


	return 0;
}