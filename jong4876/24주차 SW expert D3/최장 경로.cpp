#include<algorithm>
#include<iostream>
#include <vector>

using namespace std;

int resultRoute;
bool visited[21];

void dfs(vector<int>adj[21], int start, int routeCnt) {

	visited[start] = true;
	
	if (resultRoute < routeCnt)
		resultRoute = routeCnt;

	for (int i = 0;i < adj[start].size();i++) {

		// 다음노드 가리킴 **
		int nextNode = adj[start][i];
	
		if (visited[nextNode] == false) {
			dfs(adj, nextNode, routeCnt + 1);
			visited[nextNode] = false;
		}
	}
}


int main(int argc, char** argv) {
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {

		int N, M;
		vector<int>adj[21];

		int maxRouteCnt = 1;

		cin >> N >> M;

		for (int i = 0;i < M;i++) {
			int start, end;
			cin >> start >> end;

			adj[start].push_back(end);
			adj[end].push_back(start);
		}

		for (int i = 1;i <= N;i++) {
			resultRoute = 1;
			for (int j = 1;j <= N;j++)
				visited[j] = false;

			dfs(adj, i, 1);

			if (maxRouteCnt < resultRoute)
				maxRouteCnt = resultRoute;

		}
		cout << "#" << test_case << " " << maxRouteCnt << endl;

	}
	return 0;
}