// BOJ 14499 주사위 굴리기
// 시뮬레이션
// 2019.10.18
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int map[20][20];

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

bool isValid(int x, int y) {

    if (x < 0 || x >= n) {
        return false;
    }
    if (y < 0 || y >= m) {
        return false;
    }
    return true;
}

int main() {
    int x, y, k;
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int dice[7] = {0};
    int order;
    for (int i = 0; i < k; i++) {
        cin >> order;
        if (isValid(x+dx[order], y+dy[order])) {
            x += dx[order];
            y += dy[order];

            int temp[7] = {0};
            copy(dice, dice+7, temp);
            switch (order) {
                case 1:
                    dice[1] = temp[4];
                    dice[3] = temp[1];
                    dice[4] = temp[6];
                    dice[6] = temp[3];
                    break;
                case 2:
                    dice[1] = temp[3];
                    dice[3] = temp[6];
                    dice[4] = temp[1];
                    dice[6] = temp[4];
                    break;
                case 3:
                    dice[1] = temp[5];
                    dice[2] = temp[1];
                    dice[5] = temp[6];
                    dice[6] = temp[2];
                    break;
                case 4:
                    dice[1] = temp[2];
                    dice[2] = temp[6];
                    dice[5] = temp[1];
                    dice[6] = temp[5];
                    break;
            }
            
            if (map[x][y] == 0) {
                map[x][y] = dice[6];
            } else {
                dice[6] = map[x][y];
                map[x][y] = 0;
            }
            cout << dice[1] << endl;
        }
    }
    return 0;
}