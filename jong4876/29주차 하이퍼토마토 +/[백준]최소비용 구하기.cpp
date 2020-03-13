#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>

#define INF 2000001

using namespace std;

vector<int> vec;
int adj[1001][1001];
int N,M;

void init() {
	
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			adj[i][j] = INF;
		}
	}
}

int main() {

	cin >> N>>M;

	init();

	for (int i = 0;i < M;i++) {
		int st, end, weight;
		cin >> st >> end >> weight;

		adj[st][end] = weight;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			for (int k = 1;k <= N;k++) {
				if (adj[k][j] > adj[k][i] + adj[i][j]) {
					adj[k][j] = adj[k][i] + adj[i][j];
				}
			}
		}
	}

	int destSt, destEnd;
	cin >> destSt >> destEnd;

	cout << adj[destSt][destEnd];

	return 0;
}