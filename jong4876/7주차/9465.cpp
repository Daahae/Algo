#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int sticker[2][100001];
int dp[2][100001];

int main() {
	int T, n;
	int beforeIdx;


	cin >> T; 
	for (int k = 0;k < T;k++) {
		int sum = 0;
		cin >> n;
		for (int i = 0;i < 2;i++) { 
			for (int j = 0;j < n;j++) {
				cin >> sticker[i][j];
			}
		}
		// ���� ������� �ִ밪�� ���� dp�� �����ϴ� �������

		dp[0][0] = sticker[0][0]; 
		dp[1][0] = sticker[1][0];
		dp[0][1] = sticker[1][0] + sticker[0][1];
		dp[1][1] = sticker[0][0] + sticker[1][1];
		// basecase 

		for (int i = 2;i < n;i++) { // ���İ� ����
			dp[0][i] = sticker[0][i] + max(dp[1][i - 2],dp[1][i - 1]);
			dp[1][i] = sticker[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
			// ��Ģ������ �밢���̳� ��ĭ���� �밢��dp�� �� �ִ밪�� ����
		}

		cout << max(dp[0][n-1],dp[1][n - 1])<<endl;
		// ���� ���� dp�� ���̵Ǵ°��
	}




	return 0;
}
