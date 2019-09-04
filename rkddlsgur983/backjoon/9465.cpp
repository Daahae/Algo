// BOJ #9465 스티커 - DP
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;

int t, n;
int arr[2][MAX_N], dp[2][MAX_N];

int main() {

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < n; k++) {
                cin >> arr[j][k];
            }
        }
        // dp
        // 0번째 열의 합
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        
        // 1번째 열까지의 합
        dp[0][1] = arr[0][1] + dp[1][0];
        dp[1][1] = arr[1][1] + dp[0][0];
        
        // n번째 열까지의 합
        for (int k = 2; k < n; k++) {
            dp[0][k] = arr[0][k] + max(dp[1][k-1], dp[1][k-2]);
            dp[1][k] = arr[1][k] + max(dp[0][k-1], dp[0][k-2]);
        }

        // n번째 열까지의 최대 점수의 합
        cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    }

    return 0;
}