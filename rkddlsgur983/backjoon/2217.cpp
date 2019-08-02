// 2217 로프
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int func(int n, int arr[]) {

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] * (i+1) > max) {
            max = arr[i] * (i+1);
        }
    }
    return max;
}

int main() {
    int n;
    int arr[100001];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n, compare);

    cout << func(n, arr);

    return 0;
}