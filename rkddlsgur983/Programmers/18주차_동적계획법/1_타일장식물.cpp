// dp 타일 장식물
#include <iostream>

using namespace std;

long long solution(int N) {

    long long dp[81];

    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i-2] + dp[i-1];
    }
    long long answer = 0;
    if (N == 1) {
        answer = dp[1]*4;
    } else if (N == 2) {
        answer = (dp[1]*2 + dp[2])*2;
    } else { // N >= 3
        answer = (dp[N-2] + dp[N-1]*2 + dp[N])*2;
    }
    return answer;
}

int main() {
    cout << solution(5) << endl; // 26
    cout << solution(6) << endl; // 42
    return 0;
}