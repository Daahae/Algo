#define _crt_secure_no_warnings
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
int N,M;
int adj[101][101];
bool visited[101];
int input1, input2;
int hierachyCnt = 0;

bool bfs() {

	queue<int> Q;
	visited[input1] = true;
	Q.push(input1);

	while (!Q.empty()) {
		int Qsize = Q.size();
		hierachyCnt++; // 촌수 카운트

		for (int j = 0;j < Qsize;j++) { // level 계산을 위해선 이 반복문 꼭 필요
			int st = Q.front();
			Q.pop();
			for (int i = 1;i <= N;i++) {
				if (adj[st][i] == 1 && visited[i] == false) {
					if (i == input2) //입력받은 상대를 찾았으면 리턴
						return true;

					visited[i] = true;
					Q.push(i);
				}
			}
		}

	}
	return false;
}

int main() {
	cin >> N;
	
	cin >> input1 >> input2;

	cin >> M;

	for (int i = 0;i <= N;i++)
		visited[i] = true;

	for (int i = 0;i < M;i++) {
		int x, y;
		cin >> x >> y;
		adj[x][y] = 1;
		adj[y][x] = 1;
		visited[x] = false;
		visited[y] = false;
	}
	
	if (bfs())
		cout << hierachyCnt;
	else
		cout << -1;
}
