#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int startNum;
int minCnt = 9;
int dp[33000]; // 인덱스 number, 값 cnt

void calCount(int N, int number, int cnt) {

	// 가능한 모든 경우의 수에 대해 재귀

	if (cnt > 8)
		return;

	if (N == number) {
		minCnt = min(minCnt, cnt);
		return;
	}

	//dp[N] = cnt; // number를 만들 수 있는 경우의 수 cnt -> 필요없는거같음

	calCount(N *10 + startNum, number, cnt + 1); // 55 555 5555 ...

	calCount(N * startNum, number, cnt + 1);

	calCount(N + startNum, number, cnt + 1);

	calCount(N - startNum, number, cnt + 1);
	
	calCount(N / startNum, number, cnt + 1);
}


int solution(int N, int number) {
	int answer = 0;
	
	startNum = N;
	calCount(N, number,1);

	if (minCnt >8)
		minCnt = -1;

	return minCnt;
}
