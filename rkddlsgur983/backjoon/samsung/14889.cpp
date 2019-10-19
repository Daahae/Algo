// BOJ 14889 스타트와 링크
// 브루트 포스
// 2019.10.18
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int graph[21][21];

int min_ab = 1000000;

void DFS(bool isVisited[21], int start, int cnt) {

    if (cnt == n/2) {
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (isVisited[i] && isVisited[j]) {
                    a += graph[i][j];
                }
                if (!isVisited[i] && !isVisited[j]) {
                    b += graph[i][j];
                }
            }
        }
        int diff = a - b;
        if (diff < 0) {
            diff = diff*(-1);
        }
        min_ab = min(min_ab, diff);
        return;
    }

    for (int i = start; i <= n/2+cnt+1; i++) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            DFS(isVisited, i+1, cnt+1);
            isVisited[i] = false;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= n/2+1; i++) {
        bool isVisited[21] = {false};
        isVisited[i] = true;
        DFS(isVisited, i+1, 1);
    }

    cout << min_ab;
    return 0;
}