#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	int coin[101], dp[100001];

	cin >> n >> k; // 3 15

	for (int i = 1;i <= n;i++)
		cin >> coin[i]; // 1 5 12

	for (int i = 1;i <= k;i++)
		dp[i] = k+1; // k+1 = max 초기화, k = 15

	dp[0] = 0; // 비교의 시작을 위함

	for (int i = 1;i <= n;i++) {
		for (int j = coin[i];j <= k;j++) { // 1원으로 1원을만들기 위해 1개의 동전 필요, k 원까지 갱신
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	
	if (dp[k] == k + 1)
		cout << -1;

	else
		cout << dp[k];



	return 0;
}
