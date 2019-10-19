/* BOJ 17140 이차원 배열과 연산
 * 2019.10.19
 */
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    int r, c, k;
    cin >> r >> c >> k;

    int arr[101][101] = {0};
    int row = 3;
    int col = 3;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> arr[i][j];
        }
    }

    int time = 0;
    while (arr[r][c] != k && time <= 100) {
        if (row >= col) {
            for (int i = 1; i <= row; i++) {
                int cnt[101] = {0};
                for (int j = 1; j <= col; j++) {
                    cnt[arr[i][j]] += 1;
                }
                vector<pair<int, int> > temp;
                for (int j = 1; j <= 100; j++) {
                    if (cnt[j] > 0) {
                        temp.push_back(make_pair(j, cnt[j]));
                    }
                }
                sort(temp.begin(), temp.end(), compare);
                if (col < temp.size()*2) {
                    col = temp.size()*2;
                    if (col > 100) {
                        col = 100;
                    }
                }
                memset(arr[i], 0, sizeof(arr[i]));
                for (int j = 1, k = 0; k < temp.size(); j+=2, k++) {
                    arr[i][j] = temp[k].first;
                    arr[i][j+1] = temp[k].second;
                    if (j == 99) {
                        break;
                    }
                }
            }
        } else {
            for (int i = 1; i <= col; i++) {
                int cnt[101] = {0};
                for (int j = 1; j <= row; j++) {
                    cnt[arr[j][i]] += 1;
                }
                vector<pair<int, int> > temp;
                for (int j = 1; j <= 100; j++) {
                    if (cnt[j] > 0) {
                        temp.push_back(make_pair(j, cnt[j]));
                    }
                }
                sort(temp.begin(), temp.end(), compare);
                if (row < temp.size()*2) {
                    row = temp.size()*2;
                    if (row > 100) {
                        row = 100;
                    }
                }
                for (int j = 1; j <= 100; j++) {
                    arr[j][i] = 0;
                }
                for (int j = 1, k = 0; k < temp.size(); j+=2, k++) {
                    arr[j][i] = temp[k].first;
                    arr[j+1][i] = temp[k].second;
                    if (j == 99) {
                        break;
                    }
                }
            }
        }
        time += 1;
    }

    if (time > 100) {
        cout << -1;
    } else {
        cout << time;
    }
    return 0;
}