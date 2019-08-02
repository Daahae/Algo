// 11399 ATM
#include <iostream>
#include <algorithm>

using namespace std;

int func(int n, int arr[]) {

    int sum = arr[0];
    for (int i = 1; i < n; i++) {
            arr[i] += arr[i-1];
            sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    int arr[1001];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);    

    cout << func(n, arr);

    return 0;
}