#include<iostream>
#include<algorithm>
#include<vector>
#define INF 9999999;

using namespace std;

int adj[1001][1001];
int N,M, X;

int main() {

	// X = dest
	cin >> N >> M >> X;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			adj[i][j] = INF;
		}
		adj[i][i] = 0;
	}
	

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

	int maxWeight = 0;
	for (int i = 1;i <= N;i++) {
		maxWeight = max(maxWeight, adj[i][X] + adj[X][i]);
	}
	cout << maxWeight;
	
	

	return 0;
}

