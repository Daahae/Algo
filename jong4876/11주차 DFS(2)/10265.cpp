#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int adjArr[1001][1001];
int dp[1001][1001];
bool vertex[1001]; // 정점체크를 위함
vector<int> bus; // 버스에 타고있는 정점인지 확인?

int N, K;
int startVertex, endVertex;
int connectionCnt = 0;
int sumCnt = 0;
int maxConnectionCnt = 0;

bool isVertexInBus(int vtx) { // 버스안에 탐색할 정점이 존재하는지 판단
	for (int i = 0;i < bus.size();i++) {
		if (vtx == bus[i])
			return true;
	}
	return false;
}


void dfs(int u, int v) {

	adjArr[u][v] = -1; // 방문체크

	bus.push_back(u); // 태울놈들 버스뒷칸에 이어서 실기
	vertex[u] = false;
	connectionCnt++;

	for (int i = 1; i <= N;i++) {
		if (adjArr[v][i] == 1) {
			dfs(v, i);
		}
	}

}

int main() {

	cin >> N >> K;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			adjArr[i][j] = 0;
		}
	}

	for (int i = 1;i <= N;i++) {
		vertex[i] = true; // 정점 방문여부 true 미방문
		int tmp;
		cin >> tmp;
		adjArr[i][tmp] = 1;
		
	}


	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (adjArr[i][j] != 1)continue;

			if (vertex[j] == false) { // 이미 방문한 정점이라면 버스안에 있는지 판단
				if (!isVertexInBus(j)) // 버스안에 없으면 넘기기
					continue;
			}
			dfs(i, j);

			cout << "i : " << i << "j " << j << endl;
			cout << "  connCnt :" << connectionCnt<<endl;
			if (maxConnectionCnt + connectionCnt <= K) {
				maxConnectionCnt += connectionCnt;
			}

			else if ((maxConnectionCnt < connectionCnt) && connectionCnt <= K) { //갱신
				maxConnectionCnt = connectionCnt;
				int size = bus.size();
				for (int i = 0;i < size-connectionCnt;i++) { // 갱신되면 이전 버스놈들 내리게하기
					bus.erase(bus.begin());
				}
			}
			else if(connectionCnt >K) { // 너무커서 검사한 그룹을 못태울 때
				for (int i = 0;i < connectionCnt;i++) { // 이번에 태울려했던 놈들 내리게하기
					bus.pop_back();
				}
			}

			connectionCnt = 0;
		}
	}
	cout << maxConnectionCnt;



	return 0;
}

/*
5 5
2 1 4 3 5

5
*/
