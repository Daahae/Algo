#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int adjArr[101][101];
int dp[101][101];
int N;
int destVertex;
int startVertex;
int flag = 0;


void dfs(int cur) {

	if (dp[cur][destVertex] == 1) { // 이미 존재하는 경로라면 dp로 계산 후 종료
		//cout << "dp" << endl;
		flag = 1;
		return;
	}
	

	for (int i = 1;i <= N;i++) { // 간선 방문 여부에 따른 DFS 
		if (adjArr[cur][i] == 1) {
			//cout << cur << "->" << i << endl;
			if (i == destVertex) {
				dp[startVertex][destVertex] = 1;
				flag = 1;
				return;
			}
			adjArr[cur][i] = -1;
			dfs(i);
		}
	}

}


void resetArr() { // 행렬초기화
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (adjArr[i][j] == -1)
				adjArr[i][j] = 1;
		}
	}
}


int main() {

	cin >> N;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			adjArr[i][j] = 0;
			dp[i][j] = 0;
		}
	}



	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			int tmp;
			cin >> tmp;

			if (tmp == 1) {
				adjArr[i][j] = tmp;
				//adjArr[j][i] = tmp; // addEdge;
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			flag = 0;
			startVertex = i;
			destVertex = j;
			dfs(i);

			cout << flag << " ";
			resetArr(); // 행렬 정보를 초기화 해주어야함
		}
		cout << endl;
	}


	return 0;
}
