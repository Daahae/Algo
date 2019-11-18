#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int playerArr[101][101];
int finnishPlayer[101]; //체크 필요: 0 체크 필요X: 1

void addExtraPlay(int n, int presentPlayer, int versusPlayer, int result) {
	// 유추할 수 있는 경기결과를 추가함

	int cnt = 0;

	if (finnishPlayer[presentPlayer] == 1)
		return;

	for (int i = 1;i <= n;i++) {
		if (playerArr[presentPlayer][i] != 0)
			cnt++;
	}
	if (n - 1 == cnt) { // 검사끝난건 체크할필요없음
		finnishPlayer[presentPlayer] = 1;
		return;
	}

	for (int i = 1;i <= n;i++) {
		if (playerArr[versusPlayer][i] == result) {
			playerArr[presentPlayer][i] = result;
			addExtraPlay(n, presentPlayer, i, result);
		}
	}

}


int solution(int n, vector<vector<int>> results) {
	// 선수의 수 n
	int answer = 0;
	for (int i = 0;i < results.size();i++) {
		int winner = results[i][0];
		int loser = results[i][1];

		playerArr[winner][loser] = 1;
		playerArr[loser][winner] = -1;
	}
	// 플로이드 와샬로 추가정보 캐치
	// *** 상대한테 이겼다는건 상대가 이긴 상대는 다이김 / 졌다는건 상대의 진 상대는 다짐

	for (int i = 0;i < results.size();i++) {
		int winner = results[i][0];
		int loser = results[i][1];

		addExtraPlay(n, winner, loser, playerArr[winner][loser]);
		addExtraPlay(n, loser, winner, playerArr[loser][winner]);
	}


	for (int i = 1;i <= n;i++)
		answer += finnishPlayer[i];


	return answer;
}
