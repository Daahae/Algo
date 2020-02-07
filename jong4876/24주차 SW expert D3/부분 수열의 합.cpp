
#include<iostream>

using namespace std;
int answerCnt = 0;


void dfs(int adj[20], int idx, int sum,int N, int answer) {

	sum += adj[idx];

	if (sum > answer)
		return;

	if (sum == answer) {
		answerCnt++;
		return;
	}

	for (int i = idx + 1;i < N;i++) {
		if (sum + adj[i] <= answer)
			dfs(adj, i, sum, N, answer);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		int adj[100];
		answerCnt = 0;

		cin >> N>> K;

		for (int i = 0;i < N;i++) {
			int tmp;
			cin >> tmp;
			adj[i] = tmp;
		}

		for (int i = 0;i < N;i++)
			dfs(adj, i, 0,N,K);

		cout << "#" << test_case << " " << answerCnt<<endl;

	}
	return 0;
}