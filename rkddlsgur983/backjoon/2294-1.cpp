// BOJ #2294 동전 2
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 101;
const int MAX_K = 10001;

int n, k;
int arr[MAX_N];

bool compare(int a, int b) {
    return a > b;
}

int main() {

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 내림차순
    sort(arr, arr+n, compare);

    /* ex) 동전의 종류가 12 5 3인 경우
     * 1. 12 -> 5 -> 3
     * 2. 5 -> 3
     * 3. 3
     * 의 순서로 각 경우의 동전의 최소개수를 구함
     */
    int originK = k, cnt = 0, min = MAX_K;
    for (int i = 0; i < n; i++) {
        k = originK;
        cnt = 0;
        for (int j = i; j < n;) {
            if (arr[j] <= k) {
                k -= arr[j];
                cnt += 1;
            } else {
                if (k == 0) {
                    break;
                } else {
                    j += 1;
                }
            }
        }
        if (min > cnt && cnt > 0 && k == 0) {
            min = cnt;
        }
    }

    // 불가능
    if (min == MAX_K) {
        min = -1;
    } 

    cout << min;

    return 0;
}