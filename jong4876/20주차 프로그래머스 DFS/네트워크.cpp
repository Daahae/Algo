#include <string>
#include <vector>

using namespace std;

int visited[200];
int cnt = 0;

void dfs(int n, vector<vector<int>> computer, int startIdx) {

	visited[startIdx] = -1;

	for (int i = 0;i < n;i++) {

		// 경로있고, 자기자신아니고, 방문 안했던 곳으로 재귀
		if (computer[startIdx][i] == 1 && i != startIdx && visited[i] == 0) {
			
			dfs(n, computer, i);
		}

	}



}


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0;i < n;i++) {
		if (visited[i] == 0) {
			cnt++;
			dfs(n, computers, i);
		}
	}
	



	return cnt;
}