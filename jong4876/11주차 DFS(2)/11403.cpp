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

	if (dp[cur][destVertex] == 1) {
		//cout << "dp" << endl;
		flag = 1;
		return;
	}
	

	for (int i = 1;i <= N;i++) {
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


void resetArr() { // 인접행렬 원래대로
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
			resetArr();
		}
		cout << endl;
	}


	return 0;
}