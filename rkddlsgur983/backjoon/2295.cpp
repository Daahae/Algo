#include <iostream>
#include <algorithm>

using namespace std;

bool value[40000][10000];

int main() {
    long n, arr[1001];
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr+1, arr+n+1);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            long temp = arr[i] + arr[j];
            value[temp/10000][temp%10000] = true;
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            long temp = arr[i] - arr[j];
            if (value[temp/10000][temp%10000]) {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}