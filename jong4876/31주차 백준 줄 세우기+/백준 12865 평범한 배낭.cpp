#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<queue>

using namespace std;

int N, K;
int maxValue = 0;
vector<pair<int, int>> bag;
vector<int> visited;

bool cmp(const pair<int, int > &a, const pair<int, int> &b) {
	return a.first < b.first;
}

void BFS(int start) {

	// 다음 배낭에 넣을 인덱스 담는 큐
	queue<int> Q;
	Q.push(start);

	// 현재 가방무게
	int sumWeight = 0;
	int sumValue = 0;

	while (!Q.empty()) {

		int Qsize = Q.size();

		for (int i = 0;i < Qsize;i++) {
			int nextIdx = Q.front();
			int nextBagWeight = bag[nextIdx].first;
			int nextValue = bag[nextIdx].second;

			visited[nextIdx] = 1;
			Q.pop();
			
			sumWeight += nextBagWeight;
			sumValue += nextValue;
			maxValue = max(maxValue, sumValue);
			
			for (int j = nextIdx + 1; j < N;j++) {
		
				if (sumWeight + bag[j].first <= K && visited[j] ==0) {
					maxValue = max(maxValue, sumValue + bag[j].second);
					Q.push(j);
					
				}
			}
		}
	}
}


int main() {

	cin >> N >> K;

	// 넣을수 있는 모든 가방의 수를 대상으로 최댓값
	// BFS로 탐색
	for (int i = 0;i < N;i++) {
		int W, V;
		cin >> W >> V;

		bag.push_back(make_pair(W, V));
	}

	sort(bag.begin(), bag.end(), cmp);// cmp없어도 원하는데로 정렬아님?

	for (int i = 0;i < N;i++) {
		visited.clear();
		visited.resize(100000);
		// 첫 배낭에 넣을수 있는지 확인 후 진행
		if(bag[i].first <= K)
			BFS(i);

		
	}
	cout << maxValue;

	return 0;
}
