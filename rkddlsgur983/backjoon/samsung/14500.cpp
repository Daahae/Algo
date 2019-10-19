/* BOJ 14500 테트로미노
 * 브루트 포스
 * 2019.10.19
 */
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int map[500][500] = {0};
bool isVisited[500][500];

int max_sum;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void DFS(int x, int y, int sum, int cnt) {

    if (cnt >= 4) {
        max_sum = max(max_sum, sum);
        return;
    }

    for (int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (isValid(nx, ny) && !isVisited[nx][ny]) {
            isVisited[nx][ny] = true;
            DFS(nx, ny, sum+map[nx][ny], cnt+1);
            isVisited[nx][ny] = false;
        }
    }
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            isVisited[i][j] = true;
            DFS(i, j, map[i][j], 1);
            isVisited[i][j] = false;

            int sum = map[i][j];
            if (isValid(i-1, j+1) && isValid(i, j+1) && isValid(i+1, j+1)) {
                sum += map[i-1][j+1] + map[i][j+1] + map[i+1][j+1];
                max_sum = max(max_sum, sum);
            }
            if (isValid(i-1, j-1) && isValid(i, j-1) && isValid(i+1, j-1)) {
                sum = map[i][j];
                sum += map[i-1][j-1] + map[i][j-1] + map[i+1][j-1];
                max_sum = max(max_sum, sum);
            }
            if (isValid(i+1, j-1) && isValid(i+1, j) && isValid(i+1, j+1)) {
                sum = map[i][j];
                sum += map[i+1][j-1] + map[i+1][j] + map[i+1][j+1];
                max_sum = max(max_sum, sum);
            }
            if (isValid(i-1, j-1) && isValid(i-1, j) && isValid(i-1, j+1)) {
                sum = map[i][j];
                sum += map[i-1][j-1] + map[i-1][j] + map[i-1][j+1];
                max_sum = max(max_sum, sum);
            }
        }
    }

    cout << max_sum;
    return 0;
}