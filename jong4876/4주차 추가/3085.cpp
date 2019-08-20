#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
char candy[100][100];


bool arrIdxCheck(int x, int y, int N) {
	if (x < 0 || y < 0 || x >= N || x >= N) // 배열 범위 밖
		return false;

	return true;
}

bool arrSameCheck(int x, int y, int N, char ch ) {
	if (x < 0 || y < 0 || x >= N || x >= N) // 배열 범위 밖
		return false;

	if (candy[x][y] != ch)
		return false;

	return true;
}


int maxCheck(int posX, int posY, int N) { // 해당 위치에서의 최대 연속된 길이의 값 반환
	char dest = candy[posX][posY];
	int cnt = 0;
	int maxCnt = 0;
	int flag = 0; // 교환을 한번만 하기위한 플레그
	
	// 행 이동
	for (int i = posX;i < N;i++) {
		if (arrIdxCheck(i,posY,N) == false)
			break;
		if (candy[i][posY] == dest)
			cnt++;

		else { // 이어진문자가 끊어질 때 양옆을 비교
			if (flag == 1)
				break; // 이미 한번 바꿧으면 break

			if (arrSameCheck(i, posY - 1, N, dest) || arrSameCheck(i, posY + 1, N, dest)) { // 양옆에 이어질 문자 있으면 진행
				cnt++;
				flag = 1;
			}
			else if (arrSameCheck(i + 1, posY, N, dest)) {
				cnt++;
				break;
			}
			else
				break;
		}
	}
	if (maxCnt < cnt)
		maxCnt = cnt;
	cnt = 0;
	flag = 0; 

	for (int i = posX;i >= 0;i--) {
		if (arrIdxCheck(i, posY, N) == false)
			break;
		if (candy[i][posY] == dest)
			cnt++;

		else { // 이어진문자가 끊어질 때
			if (flag == 1)
				break; // 이미 한번 바꿧으면 break

			if (arrSameCheck(i, posY - 1, N, dest) || arrSameCheck(i, posY + 1, N, dest)) { // 양옆에 이어질 문자 있으면 진행
		
				cnt++;
				flag = 1;
			}
			else if (arrSameCheck(i -1, posY, N, dest)) {
				cnt++;
				break;
			}
			else
				break;
		}
	}
	if (maxCnt < cnt)
		maxCnt = cnt;
	cnt = 0;
	flag = 0;

	 // 열 이동 ++
	for (int j = posY;j < N; j++) {
		if (arrIdxCheck(posX, j, N) == false)
			break;
		if (candy[posX][j] == dest)
			cnt++;
		else { 
			if (flag == 1)
				break; // 이미 한번 바꿧으면 break

			if (arrSameCheck(posX-1, j, N, dest) || arrSameCheck(posX+1, j, N, dest)) { // 양옆에 이어질 문자 있으면 진행

				cnt++;
				flag = 1;
			}
			else if (arrSameCheck(posX,j+1 , N, dest)) { //  그 다음순번 교환후 스톱
				cnt++;
				break;
			}
			else
				break;
		}
	}
	if (maxCnt < cnt)
		maxCnt = cnt;
	cnt = 0;
	flag = 0;

	// 열 이동 -- 
	for (int j = posY;j >= 0; j--) {
		if (arrIdxCheck(posX, j, N) == false)
			break;
		if (candy[posX][j] == dest)
			cnt++;
		//								 p
		else { // 이어진문자가 끊어질 때 pppcp
			if (flag == 1)
				break; // 이미 한번 바꿧으면 break

			if (arrSameCheck(posX - 1, j, N, dest) || arrSameCheck(posX + 1, j, N, dest)) { // 양옆에 이어질 문자 있으면 진행
				cnt++;
				flag = 1;
			}
			else if (arrSameCheck(posX, j - 1, N, dest)) { //  그 다음순번 교환후 스톱
				cnt++;
				break;
			}
			else
				break;
		}
	}
	if (maxCnt < cnt)
		maxCnt = cnt;



	return maxCnt;
}



int main() {
	// 가로세로로 쭉 봐서 2개이상모여있는 문자열 앞 뒤로 change시도. 시도해서 연속된 문자열수가 늘어나면 최댓값 갱신

	int N;
	int i,j;
	int cnt;
	int result = 1;
	int maxCnt = 0;

	cin >> N;

	for (i = 0;i < N;i++) { 
		for (j = 0;j < N;j++) {
			cin >> candy[i][j];
		}
	}


	for (i = 0;i < N;i++) {
		for (j = 0;j < N;j++) {
			cnt = maxCheck(i, j, N);
			if (cnt > maxCnt)
				maxCnt = cnt;
		}
	}
	cout << maxCnt;

	return 0;
}