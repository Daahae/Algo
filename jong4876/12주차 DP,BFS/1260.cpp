#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, V;
int adjArr[1001][1001];
bool visited1[1001];
bool visited2[1001];

//문제 자세히 보기 #define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, V;
int adjArr[1001][1001];
bool visited1[1001];
bool visited2[1001];

//문제 자세히 보기 -> 더이상 방문할 수 있는 점이 없는 경우 종료 -> 시작점에서 도달하지 못하는 점은 방문필요 X

void dfs(int cur) {
	visited1[cur] = true;//방문 체크
	cout << cur << " ";
	for (int i = 1;i <= N;i++) {
		if (adjArr[cur][i] == 1 && visited1[i] == false)
			dfs(i);
	}
}

void bfs(int stV) {
	queue<int> Q;
	Q.push(stV);
	visited2[stV] = true; 

	while (!Q.empty()) {
		int startVertex = Q.front();
		cout << startVertex << " ";
		Q.pop();
		for (int i = 1;i <= N;i++) {
			if (adjArr[startVertex][i] == 1 && visited2[i] == false) { // 길이 있고 방문안했다면
				visited2[i] = true; // 방문체크할 이 위치 중요
				Q.push(i);
			}
		}
	}
}


int main() {
	cin >> N >> M >> V;

	for (int i = 0;i <= N;i++) {
		visited1[i] = true;
		visited2[i] = true;
	}

	for (int i = 0;i < M;i++) {
		int u, v;
		cin >> u >> v;
		adjArr[u][v] = 1;
		adjArr[v][u] = 1;
		visited1[u] = false; // 방문 예정인 곳만 visited 사용
		visited1[v] = false;
		visited2[u] = false;
		visited2[v] = false;
	}

	dfs(V);
	cout << endl;
	bfs(V);
	return 0;
}

void dfs(int cur) {
	visited1[cur] = true;//방문 체크
	cout << cur << " ";
	for (int i = 1;i <= N;i++) {
		if (adjArr[cur][i] == 1 && visited1[i] == false)
			dfs(i);
	}
}

void bfs(int stV) {
	queue<int> Q;
	Q.push(stV);
	visited2[stV] = true; 

	while (!Q.empty()) {
		int startVertex = Q.front();
		cout << startVertex << " ";
		Q.pop();
		for (int i = 1;i <= N;i++) {
			if (adjArr[startVertex][i] == 1 && visited2[i] == false) { // 길이 있고 방문안했다면
				visited2[i] = true; // 방문체크할 이 위치 중요
				Q.push(i);
			}
		}
	}
}


int main() {
	cin >> N >> M >> V;

	for (int i = 0;i <= N;i++) {
		visited1[i] = true;
		visited2[i] = true;
	}

	for (int i = 0;i < M;i++) {
		int u, v;
		cin >> u >> v;
		adjArr[u][v] = 1;
		adjArr[v][u] = 1;
		visited1[u] = false; // 방문 예정인 곳만 visited 사용
		visited1[v] = false;
		visited2[u] = false;
		visited2[v] = false;
	}
	

	dfs(V);
	cout << endl;
	bfs(V);
	return 0;
}
