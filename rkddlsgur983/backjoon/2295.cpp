// BOJ 2295 세 수의 합
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long n, arr[1001];
    vector<int> value;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr+1, arr+n+1);

    // x + y 값을 value에 저장
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            value.push_back(arr[i] + arr[j]);
        }
    }

    // value 오름차순 정렬
    sort(value.begin(), value.end());
    // value 내 중복된 x+y값 제거
    value.erase(unique(value.begin(), value.end()), value.end());

    // k - z 값을 value 내림차순 비교
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            for (int k = value.size()-1; k >= 0; k--) {
                if (value[k] == arr[i] - arr[j]) {
                    cout << arr[i];
                    return 0;
                // 내림차순 탐색에서 value 값이 더 작아지면 
                // 이하는 비교할 필요 없음
                } else if (value[k] < arr[i] - arr[j]) {
                    break;
                }
            }
        }
    }

    return 0;
}