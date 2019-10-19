// BOJ 14503 로봇 청소기
// 시뮬레이션
// 2019.10.17
#include <iostream>
#include <vector>

using namespace std;

int graph[50][50];
int clean;

int getDirection(int d) {
    d -= 1;
    if (d < 0) {
        d = 3;
    }
    return d;
}

void simulation(int r, int c, int d, int cnt, bool isFirst) {

    if (cnt >= 4) {
        if (d == 0) {
            if (graph[r+1][c] != 1) {
                simulation(r+1, c, d, 0, false);
            }
            return;
        } else if (d == 1) {
            if (graph[r][c-1] != 1) {
                simulation(r, c-1, d, 0, false);
            }
            return;
        } else if (d == 2) {
            if (graph[r-1][c] != 1) {
                simulation(r-1, c, d, 0, false);
            }
            return;
        } else if (d == 3) {
            if (graph[r][c+1] != 1) {
                simulation(r, c+1, d, 0, false);
            }
            return;
        }
    } else {
        if (isFirst) {
            graph[r][c] = 2;
            clean += 1;
        }
        d = getDirection(d);
    }

    if (d == 0) {
        if (graph[r-1][c] == 0) {
            simulation(r-1, c, d, 0, true);
        } else {
            simulation(r, c, d, cnt+1, false);
        }
    } else if (d == 1) {
        if (graph[r][c+1] == 0) {
            simulation(r, c+1, d, 0, true);
        } else {
            simulation(r, c, d, cnt+1, false);
        }
    } else if (d == 2) {
        if (graph[r+1][c] == 0) {
            simulation(r+1, c, d, 0, true);
        } else {
            simulation(r, c, d, cnt+1, false);
        }
    } else if (d == 3) {
        if (graph[r][c-1] == 0) {
            simulation(r, c-1, d, 0, true);
        } else {
            simulation(r, c, d, cnt+1, false);
        }
    }
}

int main() {
    int n, m;
    int r, c, d;

    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    simulation(r, c, d, 0, true);

    cout << clean;
    return 0;
}