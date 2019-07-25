// 11047 동전 0
#include <iostream>

using namespace std;

int func(int n, int k, int value[]) {
    
    int count = 0;

    for (int i = n-1; i >= 0; i--) {
        
        if (k == 0) break;

        count += k / value[i];
        k %= value[i];
    }

    return count;
}

int main() {
    int n, k;
    int value[11];
    int count = 0;

    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << func(n, k, value);

    return 0;
}