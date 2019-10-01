#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;
vector<vector<int>> adjArr;
vector<bool> visisted;
int connectionCnt = 0; // ���� ����� ����


void dfs(int cur) {
	visisted[cur] = true; // ���� �湮üũ
	//cout << cur << " �湮" << endl;
	for (int next : adjArr[cur]) { // ��� ���������� ����
		if (visisted[next] == false) { // ������ �湮���� �ʾ�����
			dfs(next);
		}
	}
}

void addEdge(int u,int v) {// ���͸� ����ؼ� ����Ʈó�� ��� ��������
	adjArr[u].push_back(v);
	adjArr[v].push_back(u);
}


int main() {
	int N, M;

	cin >> N >> M; // ����, ���� adjArr[N][N]


	adjArr.resize(N+1); // ������ ���� �ʼ�
	visisted.resize(N+1);

	for (int i = 0;i < M;i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}

	for (int i = 1;i <= N;i++) { // ������ ������������ �湮�ϱ� ���� sort
		visisted[i] = false;
		sort(adjArr[i].begin(), adjArr[i].end());
	}

	for (int i = 1;i <= N;i++) {
		//cout << "i���� ����" << endl;
		if (visisted[i])
			continue;
		dfs(i);
		connectionCnt++;
	}

	cout << connectionCnt << endl;
	return 0;
}