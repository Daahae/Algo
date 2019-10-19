// BOJ 13458 시험 감독
// 2019.10.19
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int b, c;
    cin >> b >> c;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        arr[i] -= b;
        sum += 1;
        if (arr[i] > 0) {
            if (arr[i]%c == 0) {
                sum += arr[i]/c;
            } else {
                sum += arr[i]/c +1;
            }
        }
    }
    cout << sum;
    return 0;
}