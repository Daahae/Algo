#include<iostream>
#include<algorithm>

using namespace std;

int answer = 0;
int dp[10001][4];

//dp, 만들어 놓고 시작하기
int main() {

	int T;

	cin >> T;

	// dp[n][i] n을 만들 떄 i를 끝 수로 쓰는 경우
	dp[1][1] = 1;

	dp[2][1] = 1;
	dp[2][2] = 1;

	// 1+1+1 = 3
	dp[3][1] = 1;
	// 1+2 = 3
	dp[3][2] = 1;
	// 3 =3
	dp[3][3] = 1;

	// 오름차순 조합을 유지하며 dp **
	for (int i = 4;i <= 10000;i++) {
		
		// 1 이하의 수로 구성해야함(오름차순을 위해) && 마지막 조합을 1로 구성 
		dp[i][1] = dp[i - 1][1];

		// 2 이하의 수 && 마지막 조합을 2로 구성 ex) 1+1+2
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];

		// 3
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}

	for (int i = 0;i < T;i++) {
		int num, sum = 0;
		cin >> num;
		
		for (int j = 1;j <= 3;j++) 
			sum += dp[num][j];
		
		cout << sum<<endl;
	}
	return 0;
}
