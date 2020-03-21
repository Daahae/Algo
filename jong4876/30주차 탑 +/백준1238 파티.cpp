#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>

#define INF 99999999;

using namespace std;

int adj[1001][1001];
int N, M, X;

int main() {

	// X = dest
	scanf("%d %d %d", &N, &M, &X);

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			adj[i][j] = INF;
		}
		adj[i][i] = 0;
	}

	//getchar();
	for (int i = 0;i < M;i++) {
		int st, end, weight;
		scanf("%d %d %d", &st, &end, &weight);

		adj[st][end] = weight;
	}


	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {

			// 어차피 비교할 필요 없음 ** 시간줄이기
			if (adj[i][j] == 99999999)continue;

			for (int k = 1;k <= N;k++) {
				if (adj[k][j] > adj[k][i] + adj[i][j]) {
					adj[k][j] = adj[k][i] + adj[i][j];
				}
			}
		}
	}

	int maxWeight = 0;
	for (int i = 1;i <= N;i++) 
		maxWeight = max(maxWeight, adj[i][X] + adj[X][i]);
	
	printf("%d", maxWeight);
	return 0;
}

