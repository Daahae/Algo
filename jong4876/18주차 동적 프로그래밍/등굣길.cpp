// 등굣길
#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long dp[101][101];


int solution(int m, int n, vector<vector<int>> puddles) {

	dp[1][1] = 1;

	for (int i = 0;i < puddles.size();i++) {
		dp[puddles[i][1]][puddles[i][0]] = -1;
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (dp[i][j] == -1) //침수위치
				continue;

			if (dp[i - 1][j] != -1)
				dp[i][j] += dp[i - 1][j];

			if (dp[i][j - 1] != -1)
				dp[i][j] += dp[i][j - 1];

			dp[i][j] = dp[i][j] % 1000000007;

		}
	}
	return dp[n][m];
}