// 2231 분해합
#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i = 1; i < n; i++) {
        int sum = 0;
        int origin = i, value = i;

        while (value > 0) {
            sum += value % 10;
            value /= 10;
        }

        if (origin + sum == n) {
            cout << origin;
            return 0;
        }
    }
    cout << 0;

    return 0;
}