// BOJ queue 3078 좋은 친구
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n, k;
    string input;
    queue<int> q[21];

    cin >> n >> k;

    long cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> input;
        int length = input.length();
        if (q[length].empty()) {
            q[length].push(i);
        } else {
            while ((i - q[length].front()) > k) {
                q[length].pop();
                if (q[length].empty()) {
                    break;
                }
            }
            cnt += q[length].size();
            q[length].push(i);
        }
    }

    cout << cnt;
    return 0;
}