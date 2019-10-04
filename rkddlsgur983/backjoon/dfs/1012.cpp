// BOJ DFS 1012 유기농 배추
#include <iostream>

using namespace std;

// 상하좌우 확인 시 배열 범위 안인지 확인
bool isValid(int m, int n, int x, int y) {

    if (x < 0 || x >= m) {
        return false;
    }
    if (y < 0 || y >= n) {
        return false;
    }
    return true;
}

int DFS(bool graph[50][50], bool isVisited[50][50], int m, int n, int x, int y) {

    // 노드 방문
    isVisited[x][y] = true;
    
    if (isValid(m, n, x, y-1) && graph[x][y-1] && !isVisited[x][y-1]) { // 상
        DFS(graph, isVisited, m, n, x, y-1);
    }
    if (isValid(m, n, x, y+1) && graph[x][y+1]&& !isVisited[x][y+1]) { // 하
        DFS(graph, isVisited, m, n, x, y+1);
    }
    if (isValid(m, n, x-1, y) && graph[x-1][y] && !isVisited[x-1][y]) { // 좌
        DFS(graph, isVisited, m, n, x-1, y);
    }
    if (isValid(m, n, x+1, y) && graph[x+1][y] && !isVisited[x+1][y]) { // 우
        DFS(graph, isVisited, m, n, x+1, y);
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        bool graph[50][50] = {false};
        bool isVisited[50][50] = {false}; 
        int m, n, k;

        cin >> m >> n >> k;

        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            graph[x][y] = true;
        }

        int cnt = 0;
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < n; b++) {
                if (graph[a][b] && !isVisited[a][b]) {
                    DFS(graph, isVisited, m, n, a, b);
                    cnt += 1;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}