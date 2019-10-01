#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;
vector<vector<int>> adjArr;
vector<bool> visisted;
int connectionCnt = 0; // 연결 요소의 개수


void dfs(int cur) {
	visisted[cur] = true; // 정점 방문체크
	//cout << cur << " 방문" << endl;
	for (int next : adjArr[cur]) { // 모든 인접간선에 대해
		if (visisted[next] == false) { // 이전에 방문하지 않았으면
			dfs(next);
		}
	}
}

void addEdge(int u,int v) {// 벡터를 사용해서 리스트처럼 사용 간선생성
	adjArr[u].push_back(v);
	adjArr[v].push_back(u);
}


int main() {
	int N, M;

	cin >> N >> M; // 정점, 간선 adjArr[N][N]


	adjArr.resize(N+1); // 사이즈 지정 필수
	visisted.resize(N+1);

	for (int i = 0;i < M;i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}

	for (int i = 1;i <= N;i++) { // 간선을 오름차순으로 방문하기 위해 sort
		visisted[i] = false;
		sort(adjArr[i].begin(), adjArr[i].end());
	}

	for (int i = 1;i <= N;i++) {
		//cout << "i에서 시작" << endl;
		if (visisted[i])
			continue;
		dfs(i);
		connectionCnt++;
	}

	cout << connectionCnt << endl;
	return 0;
}