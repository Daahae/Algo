// 10250 ACM 호텔
#include <iostream>

using namespace std;

int func(int h, int w, int n) {
    return (((n - 1) % h) + 1) * 100 + (n - 1) / h + 1;
}

int main() {
    int t;
    int h, w, n;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> h >> w >> n;
        cout << func(h, w, n) << endl;
    }

    return 0;
}