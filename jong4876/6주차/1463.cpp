#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int dp[1000000]; // 메모제이션을 위한 배열

int func(int n) {
	if (n == 1) return 0; // n=1일땐 연산안함. 베이스케이스
	if (dp[n] != -1) return dp[n]; // 이미 계산한 값은 그냥 반환

	int cnt = func(n - 1) + 1; // n = 2부터 3,4,5... 전체순환
	if (n % 3 == 0)cnt = min(cnt, func(n / 3) + 1);

	if (n % 2 == 0)cnt = min(cnt, func(n / 2) + 1);

	dp[n] = cnt; // n = 2부터 메모제이션 값을 차례로 저장
	return cnt;
	
}

int main() {
	int N;
	cin >> N;
	fill(dp, dp + N+1, -1); //-1로 채움
	cout << func(N);
	return 0;
}


