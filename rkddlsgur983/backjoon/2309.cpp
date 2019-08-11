// 2309 일곱 난쟁이
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

const int N = 9;
const int SUM = 100;

int sum(int arr[]) {
    return accumulate(arr, arr + N, 0);
}

pair<int, int> func(int arr[], int sum) {
    
    pair<int, int> except;

    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (sum - (arr[i] + arr[j]) == SUM) {
                return except = pair<int, int>(i, j);
            }
        }
    }
}

int main() {
    int arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);
    
    pair<int, int> except = func(arr, sum(arr));

    for (int k = 0; k < N; k++) {
        if (k != except.first && k != except.second) {
            cout << arr[k] << endl;
        }
    }

    return 0;
}