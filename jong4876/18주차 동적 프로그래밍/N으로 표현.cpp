#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;

int startNum;
int minCnt = 999999;
int dp[33000]; // 인덱스 number, 값 cnt

void calCount(int N, int number, int cnt) {

	if (cnt > 9)
		return;

	if (N == number) {
		minCnt = min(minCnt, cnt);
		return;
	}

	//dp[N] = cnt; // number를 만들 수 있는 경우의 수 cnt

	
	calCount(N*10 - N, number, cnt + 1);

	calCount(N +startNum, number, cnt + 1);
	
	calCount(N+ 1, number, cnt + 1); // startNum / startNum = 1
	
	calCount(N / startNum, number, cnt + 1);

	
}


int solution(int N, int number) {
	int answer = 0;
	
	startNum = N;
	calCount(N, number,1);

	if (minCnt == 999999)
		minCnt = -1;

	return minCnt;
}