#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int>> dp; // 현재층까지의 최댓값, 출발 위치
int maxSum = -1;
int sum = 0;

int isInArr(int i, int j){ //삼각형 내부인지 여부
	if (j == 0)
		return -1;

	else if (i == j)
		return 1;

	else
		return 0;


}

int getMaxFloor(vector<vector<int>> triangle) { // 누적합 구하기

	int i; 

	// 삼각형의 왼쪽 외부, 오른쪽 외부, 삼각형 내부로 구별하여 각각의 누적합을 기존벡터에 대입
	for (i = 1;i < triangle.size();i++) {
		int presentFloor = i;
		for (int j = 0;j < triangle[presentFloor].size();j++) {
			int parentVal;
			if (isInArr(presentFloor, j) == 0) { // 삼각형 내부
				parentVal = max(triangle[presentFloor - 1][j - 1], triangle[presentFloor - 1][j]);
			}
			else if(isInArr(presentFloor, j) == -1){ // 맨 왼쪽
				parentVal = triangle[presentFloor - 1][j];
			}
			else if (isInArr(presentFloor, j) == 1) { // 맨 오른쪽
				parentVal = triangle[presentFloor - 1][j-1];
			}

			triangle[presentFloor][j] += parentVal;
		}
	}

	for (int j = 0;j < triangle.size();j++) {
		maxSum = max(triangle[triangle.size()-1][j], maxSum);
	}

	return maxSum;
}


int solution(vector<vector<int>> triangle) {
	int answer = 0;
	answer = getMaxFloor(triangle);

	return answer;
}