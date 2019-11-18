#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int playerArr[100][100] = { -1, };

void addExtraPlay(int n,int presentPlayer, int versusPlayer, int result) {

	for (int i = 1;i <= n;i++) {
		if (playerArr[versusPlayer][i] == result) {
			playerArr[presentPlayer][i] = result;
			addExtraPlay(n, presentPlayer, i, result);
		}
	}

}


int solution(int n, vector<vector<int>> results) {// 선수의 수 n
	int answer = 0;
	for (int i = 0;i < results.size();i++) {
		int winner = results[i][0];
		int loser = results[i][1];

		playerArr[winner][loser] = 1;
		playerArr[loser][winner] = -1; 
	}
	// 플로이드 와샬로 추가정보 캐치?
	// player 이름은 12345순?

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cout << playerArr[i][j] << " ";
		}
		cout << endl;
	}

	
	for (int i = 1;i <= n;i++) { // floyd -warshall
		// 상대한테 이겼다는건 상대가 이긴 상대는 다이김 / 졌다는건 상대의 진 상대는 다짐
		for (int j = 1;j <= n;j++) {
			if (i == j)
				continue;

			if (playerArr[i][j] != -1) {
				//addExtraPlay(n, i, j, playerArr[i][j]);
			}
		}
	}



	for (int i = 1;i <= n;i++) {
		int rank = 0;
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