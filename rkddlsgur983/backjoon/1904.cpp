// BOJ #1904 01타일 - DP, 피보나치
#include <iostream>

using namespace std;

const int DIVIDE_NUM = 15746;

int main() {

    int n;
    cin >> n;

    int x = 0, y = 1, z;
    for (int i = 0; i < n; i++) {
        z = (x + y) % DIVIDE_NUM;
        x = y;
        y = z;
    }

    cout << z;

    return 0;
}