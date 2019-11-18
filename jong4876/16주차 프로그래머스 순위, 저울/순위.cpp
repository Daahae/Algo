#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int playerArr[101][101];
int checkPlayer[101][101];

void addExtraPlay(int n, int presentPlayer, int versusPlayer, int result) {
	// 유추할 수 있는 경기결과를 추가함

	int cnt = 0;
	
	if (checkPlayer[presentPlayer][versusPlayer] == 0) { // 동적 프로그래밍, 이미 한번 한 경로는 계산필요없음
		checkPlayer[presentPlayer][versusPlayer] = 1;
	}
	else //  이미 겪었던 경로는 종료
		return;

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


	// 순위를 낼 수 있는 player 수 = 승패가 다 나온 player 수
	// 구해서 answer에 더함, 순위가 몇위인지는 중요하지않음
	for (int i = 1;i <= n;i++) {
		int presentPlayer = i;
		int minusCnt = 1;
		for (int j = 1;j <= n;j++) {
			if (i == j)
				continue;

			if (playerArr[presentPlayer][j] == 0) {
				minusCnt = -1;
				break;
			}
		}
		if (minusCnt == 1)
			answer++;
	}



	return answer;
}
