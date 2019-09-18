// BOJ Stack 1725 히스토그램
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n, input;
    long maxArea = 0;
    vector<int> arr;
    stack<int> s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        arr.push_back(input);
    }

    for (int i = 0; i <= n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            int index = s.top();
            long width;
            s.pop();
            if (s.empty()) {
                width = i;
            } else {
                width = i - s.top() - 1;
            }
            maxArea = max(maxArea, arr[index] * width);
        }
        s.push(i);
    }

    cout << maxArea;
    return 0;
}