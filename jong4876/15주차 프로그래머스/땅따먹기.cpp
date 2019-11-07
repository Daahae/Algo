#include <iostream>
#include <vector>
using namespace std;
int maxRow;
int score = 0;
int maxScore = 0;

bool isInArr(int col) {
	if (col >= 0 && col < 4)
		return true;

	return false;

}

void getNextCol(int presentRow, int col, vector<vector<int> > land){

	if (presentRow >= maxRow) { //basecase
		if (score > maxScore)
			maxScore = score;
		return;
	}
	score += land[presentRow][col];

	for (int i = 0;i < 4;i++) {
		int tmp = score;
		if (i != col)
			getNextCol(presentRow+1, i, land);

		score = tmp;
	}

}

int solution(vector<vector<int> > land)
{
	int answer = 0;
	int col = 4;
	maxRow = land.size();


	for (int i = 0;i < col;i++) { // 처음 4개 스타트 다 해보기
		score = 0;
		getNextCol(0,i, land);
	}




	return maxScore;
}