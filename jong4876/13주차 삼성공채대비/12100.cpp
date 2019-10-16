#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int adj[21][21];
int N;
int changeFlag = -1;
int maxCnt = -1;

void copyArr(int Arr[21][21], int Brr[21][21]) {

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			Arr[i][j] = Brr[i][j];
		}
	}
}


bool isInArr(int x, int y) {
	if (x<0 && x >= N)
		return false;

	if (y<0 && y >= N)
		return false;

	return true;

}



void left() { // 왼쪽으로 밀기
	for (int i = 0;i < N;i++) {
		queue<int> Q;

		for (int j = 0;j < N;j++) {
			if(adj[i][j] != 0)
				Q.push(adj[i][j]);
		}
		int size = Q.size();
		for (int j = 0;j < N;j++) {
			adj[i][j] = 0;
		}
		int j = 0;
		while (!Q.empty()) {
			int front = Q.front();
			Q.pop();
			if (Q.empty()) {
				adj[i][j] = front;
				break;
			}

			if (front == Q.front()) {
				adj[i][j] = front * 2;
				Q.pop();
			}
			else {
				adj[i][j] = front;
			}
			j++;
		}
	}
}

void right() { // 오른쪽으로 밀기
	for (int i = 0;i < N;i++) {
		queue<int> Q;
		
		for (int j = N-1;j >= 0;j--) {
			if (adj[i][j] != 0)
				Q.push(adj[i][j]);
		}

		for (int j = N-1;j >= 0;j--) {
			adj[i][j] = 0;
		}
		int j = N-1;
	//cout << "??" << endl;
		while (!Q.empty() && j>=0) {
			int front = Q.front();
			Q.pop();
			if (Q.empty()) {
				adj[i][j] = front;
				break;
			}

			if (front == Q.front()) {
				adj[i][j] = front * 2;
				Q.pop();
			}
			else {
				adj[i][j] = front;
			}
			j--;
		}
	}
}

void up() { // 위로 밀기
	for (int i = 0;i < N;i++) {
		queue<int> Q;

		for (int j = 0;j < N;j++) {
			if (adj[j][i] != 0)
				Q.push(adj[j][i]);
		}
		int size = Q.size();
		for (int j = 0;j < N;j++) {
			adj[j][i] = 0;
		}
		int j = 0;
		while (!Q.empty()) {
			int front = Q.front();
			Q.pop();
			if (Q.empty()) {
				adj[j][i] = front;
				break;
			}

			if (front == Q.front()) {
				adj[j][i] = front * 2;
				changeFlag = 1;
				Q.pop();
			}
			else {
				adj[j][i] = front;
			}
			j++;
		}
	}
}

void down() { // 아래로 밀기
	for (int i = 0;i < N;i++) {
		queue<int> Q;

		for (int j = N-1;j >= 0;j--) {
			if (adj[j][i] != 0)
				Q.push(adj[j][i]);
		}
		int size = Q.size();
		for (int j = 0;j < N;j++) {
			adj[j][i] = 0;
		}
		int j = N-1;
		while (!Q.empty()) {
			int front = Q.front();
			Q.pop();
			if (Q.empty()) {
				adj[j][i] = front;
				break;
			}

			if (front == Q.front()) {
				adj[j][i] = front * 2;
				changeFlag = 1;
				Q.pop();
			}
			else {
				adj[j][i] = front;
			}
			j--;
		}
	}
}

void combine(int order){

	switch (order) {
	case 0:
		left();
		break;

	case 1:
		right();
		break;

	case 2:
		up();
		break;

	case 3:
		down();
		break;
	}


}

void printArr() {
	for (int i = 0;i < N;i++) { // print
		for (int j = 0;j < N;j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int cnt) {

	if (cnt == 5) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				maxCnt = max(adj[i][j], maxCnt);
			}
		}
		cout << "maCnt : " << maxCnt << endl; // 모든 count5 의 경우에서 최댓값구함
		return;
	}

	int tmpAdj[21][21];
	copyArr(tmpAdj, adj); // 모든 방법 순회 후 이전 뿌리로 돌아오기 위함
	for (int i = 0;i < 4;i++) {
		// 상하좌우 모든 미는경우를 가지치기 *****
		combine(i);
		dfs(cnt + 1); 
		copyArr(adj, tmpAdj);
	}
}

int main() {

	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int tmp;
			cin >> tmp;
			adj[i][j] = tmp;
		}
	}
	
	dfs(0);

	//printArr();

	cout << maxCnt << endl;

}
