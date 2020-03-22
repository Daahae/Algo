#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<queue>

using namespace std;

int visited[100001];
int minSec= 0;

// 다음 인덱스로 넘어갈 수 있는지
bool isGoNext(int next) {
	if (next < 0 || next>100000)
		return false;

	if (visited[next] == 1)
		return false;

	return true;

}

void BFS(int N,int K) {

	queue<int> Q;
	Q.push(N);

	while (!Q.empty()) {
		int Qsize = Q.size();

		// 다음 진행할 경로 Q에 삽입
		for (int i = 0;i < Qsize;i++) {
			int st = Q.front();
			visited[st] = 1;

			if (st == K)
				return;

			Q.pop();

			int next = st + 1;
			if(isGoNext(next))
				Q.push(next);
			
			next = st - 1;
			if (isGoNext(next))
				Q.push(next);

			next = 2 * st;
			if (isGoNext(next))
				Q.push(next);
			
		}

		//다음 경로를 모두 탐색 완료 -> sec 증가
		minSec++;
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	BFS(N, K);

	cout << minSec;
	return 0;
}
