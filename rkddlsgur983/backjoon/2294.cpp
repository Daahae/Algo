// BOJ #2294 동전 2 - DP
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 101;
const int MAX_K = 10001;

int n, k;
int arr[MAX_N], dp[MAX_K];

int main() {

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // 동적배열 초기화
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = MAX_K;
    }

    // dp
    for (int i = 1; i <= n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }

    // 불가능
    if (dp[k] == MAX_K) {
        dp[k] = -1;
    }

    cout << dp[k];

    return 0;
}