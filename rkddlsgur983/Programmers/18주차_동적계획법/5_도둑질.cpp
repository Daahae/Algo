/* 도둑질
 * fail
 * 2019.12.11
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    vector<int> dp(money.size());
    int answer = 0;
    for (int i = 0; i < money.size(); i++) {
        fill(dp.begin(), dp.end(), 0);
        dp[0] = money[i];
        dp[1] = max(money[(i+1)%money.size()], dp[0]);
        for (int j = 2; j < money.size(); j++) {
            int index = (i+j) % money.size();
            dp[j] = max(money[index] + dp[j-2], dp[j-1]);
        }
        int max_value = *max_element(dp.begin(), dp.end());
        cout << max_value << '\n';
        answer = max(answer, max_value);
    }
    return answer;
}

int main() {
    vector<int> money({1, 2, 3, 1});
    cout << solution(money); // 4
    return 0;
}