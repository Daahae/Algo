#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;
int V[101];
int N, S, M;
int maxVol = -1;
bool dp[1001][101];

void DFS(int volume, int idx) {

	// 범위를 벗어날 시 종료
	if (volume < 0 || volume>M)
		return;

	// 끝곡에 다다른다면 최댓값 갱신 후 종료
	if (idx == N) {
		maxVol = max(maxVol, volume);
		return;
	}

	// 해당 케이스가 이미 있는 케이스라면 굳이 재귀할 필요 없음 -> 종료
	if (dp[volume][idx] == true) 
		return;
	
	dp[volume][idx] = true;

	// 볼륨 더하기로 재귀
	DFS(volume + V[idx], idx + 1);

	// 볼륨 빼기로 재귀
	DFS(volume - V[idx], idx + 1);
}

int main() {

	// 무조건 볼륨 바꿔야 함
	//  0 <= answer <= M, S = start
	cin >> N >> S >> M;

	// 5 -5 +3 +7
	for (int i = 0;i < N;i++)
		cin >> V[i];

	
	DFS(S, 0);

	cout << maxVol;

	return 0;
}
