#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000000];

int solution(vector<int> money) {
	int answer = 0;


	dp[0] = money[0];
	dp[1] = money[1];

	for (int i = 2;i < money.size();i++) {
		dp[i] = max(money[i] + dp[i - 2], dp[i - 1]);
	}



	return dp[money.size()-1];
}