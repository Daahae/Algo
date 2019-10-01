#define _crt_secure_no_warnings
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int adj[51][51];
int row, col, T, K;

bool isInAdj(int x, int y) { // �迭 ������ �ε������� �Ǵ��Լ�
	if (x < 0 || x >= row)
		return false;

	if (y  < 0 || y >= col)
		return false;

	return true;
}

void dfs(int x,int y) {
	adj[x][y] = -1; // �湮 : -1

	for (int i = -1;i <= 1;i++) { // �����¿� Ž��
		if (isInAdj(x+i, y)) {// �迭 �����ȿ� �����ϰ�
			if(adj[x+i][y] == 1) // �湮���� �ʰ� ���� �ִٸ�
				dfs(x + i, y);
		}
		if (isInAdj(x, y+i)) {
			if (adj[x][y+i] == 1) 
				dfs(x, y+i);
		}
	}
}


int main() {

	cin >> T;

	for (int z = 0;z < T;z++) {
		int connectionCnt = 0;
		cin >> row >> col >> K;

		//resize
		int N = max(row, col);

		//initialize
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				adj[i][j] = 0;
			}
		}

		for (int i = 0;i < K;i++) {
			int x, y;
			cin >> x >> y;
			adj[x][y] = 1;
		}
		
		//dfs
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				if (adj[i][j] != 1)
					continue;

				dfs(i, j);
				connectionCnt++;
			}
		}
		cout << connectionCnt << endl;
	}


	return 0;
}