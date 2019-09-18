// BOJ Stack #2304 창고 다각형
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n, l, h;
    int index, max, area = 0;
    vector<pair<int, int>> col;
    stack<pair<int, int>> s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> h;
        col.push_back(pair<int, int>(l, h));
    }

    sort(col.begin(), col.end(), compare);

    // 최대 높이를 가진 기둥의 인덱스
    index = 0;
    max = col[0].second;
    for (int i = 1; i < n; i++) {
        if (max < col[i].second) {
            max = col[i].second;
            index = i;
        }
    }

    // 최대 높이의 기둥 왼쪽 면적의 합
    s.push(col[0]);
    for (int i = 1; i <= index; i++) {
        if (s.top().second <= col[i].second) {
            area += s.top().second * (col[i].first - s.top().first);
            s.push(col[i]);
        }
    }
    while(!s.empty()) {
        s.pop();
    }

    // 최대 높이 기둥의 면적
    area += col[index].second;

    // 최대 높이 기둥 오른쪽 면적의 합
    if (n > 1) {
        s.push(col[n-1]);
        for(int i = n-2; i >= index; i--) {
            if (s.top().second <= col[i].second) {
                area += s.top().second * (s.top().first - col[i].first);
                s.push(col[i]);
            }
        }
    }

    cout << area;
    return 0;
}