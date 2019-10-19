// BOJ 15683 감시
// 브루트 포스
// 2019.10.19
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int map[9][9];

int dx[6] = {0, 1, 0, -1, 0, 1};
int dy[6] = {1, 0, -1, 0, 1, 0};

vector<pair<pair <int, int>, int>> cctv; // 좌표, 번호

int min_area = 65;

bool isValid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void DFS(int c) {

    if (c >= cctv.size()) {
        int area = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j] == 0) {
                    area += 1;
                }
            }
        }
        min_area = min(min_area, area);
        return;
    }
    
    int temp[9][9] = {0};
    copy(&map[0][0], &map[0][0] + 9*9, &temp[0][0]);
    int x;
    int y;
    switch (cctv[c].second) {
        case 1:
            for (int j = 0; j < 4; j++) {
                x = cctv[c].first.first;
                y = cctv[c].first.second;
                while (isValid(x+dx[j], y+dy[j])
                && map[x+dx[j]][y+dy[j]] != 6) {
                    map[x+dx[j]][y+dy[j]] = -1;
                    x += dx[j];
                    y += dy[j];
                }
                DFS(c+1);
                copy(&temp[0][0], &temp[0][0] + 9*9, &map[0][0]);
            }
            break;

        case 2:
            for (int j = 0; j < 2; j++) {
                x = cctv[c].first.first;
                y = cctv[c].first.second;
                while (isValid(x+dx[j], y+dy[j])
                && map[x+dx[j]][y+dy[j]] != 6) {
                    map[x+dx[j]][y+dy[j]] = -1;
                    x += dx[j];
                    y += dy[j];
                }
                x = cctv[c].first.first;
                y = cctv[c].first.second;
                while (isValid(x+dx[j+2], y+dy[j+2])
                && map[x+dx[j+2]][y+dy[j+2]] != 6) {
                    map[x+dx[j+2]][y+dy[j+2]] = -1;
                    x += dx[j+2];
                    y += dy[j+2];
                }
                DFS(c+1);
                copy(&temp[0][0], &temp[0][0] + 9*9, &map[0][0]);
            }
            break;

        case 3:
            for (int j = 0; j < 4; j++) {
                x = cctv[c].first.first;
                y = cctv[c].first.second;
                while (isValid(x+dx[j], y+dy[j])
                && map[x+dx[j]][y+dy[j]] != 6) {
                    map[x+dx[j]][y+dy[j]] = -1;
                    x += dx[j];
                    y += dy[j];
                }
                x = cctv[c].first.first;
                y = cctv[c].first.second;
                while (isValid(x+dx[j+1], y+dy[j+1])
                && map[x+dx[j+1]][y+dy[j+1]] != 6) {
                    map[x+dx[j+1]][y+dy[j+1]] = -1;
                    x += dx[j+1];
                    y += dy[j+1];
                }
                DFS(c+1);
                copy(&temp[0][0], &temp[0][0] + 9*9, &map[0][0]);
            }
            break;

        case 4:
            for (int j = 0; j < 4; j++) {
                x = cctv[c].first.first;
                y = cctv[c].first.second;
                while (isValid(x+dx[j], y+dy[j])
                && map[x+dx[j]][y+dy[j]] != 6) {
                    map[x+dx[j]][y+dy[j]] = -1;
                    x += dx[j];
                    y += dy[j];
                }
                x = cctv[c].first.first;
                y = cctv[c].first.second;
                while (isValid(x+dx[j+1], y+dy[j+1])
                && map[x+dx[j+1]][y+dy[j+1]] != 6) {
                    map[x+dx[j+1]][y+dy[j+1]] = -1;
                    x += dx[j+1];
                    y += dy[j+1];
                }
                x = cctv[c].first.first;
                y = cctv[c].first.second;
                while (isValid(x+dx[j+2], y+dy[j+2])
                && map[x+dx[j+2]][y+dy[j+2]] != 6) {
                    map[x+dx[j+2]][y+dy[j+2]] = -1;
                    x += dx[j+2];
                    y += dy[j+2];
                }
                DFS(c+1);
                copy(&temp[0][0], &temp[0][0] + 9*9, &map[0][0]);
            }
            break;

        case 5:
            for (int j = 0; j < 4; j++) {
                x = cctv[c].first.first;
                y = cctv[c].first.second;
                while (isValid(x+dx[j], y+dy[j])
                && map[x+dx[j]][y+dy[j]] != 6) {
                    map[x+dx[j]][y+dy[j]] = -1;
                    x += dx[j];
                    y += dy[j];
                }
            }
            DFS(c+1);
            copy(&temp[0][0], &temp[0][0] + 9*9, &map[0][0]);
            break;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5) {
                cctv.push_back(make_pair(make_pair(i, j), map[i][j]));
            }
        }
    }

    DFS(0);

    cout << min_area;
    return 0;
}