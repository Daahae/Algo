// BOJ DFS 1743 음식물 피하기
#include <iostream>
#include <algorithm>

using namespace std;

bool graph[101][101], isVisited[101][101];
int m, n;

// 상하좌우 확인 시 배열 범위 안인지 확인
bool isValid(int x, int y) {

    if (x < 1 || x > m) {
        return false;
    }
    if (y < 1 || y > n) {
        return false;
    }
    return true;
}

int DFS(int x, int y, int count) {

    // 노드 방문
    isVisited[x][y] = true;
    count += 1;
    
    if (isValid(x, y-1) && graph[x][y-1] && !isVisited[x][y-1]) { // 상
        count = DFS(x, y-1, count);
    }
    if (isValid(x, y+1) && graph[x][y+1] && !isVisited[x][y+1]) { // 하
        count = DFS(x, y+1, count);
    }
    if (isValid(x-1, y) && graph[x-1][y] && !isVisited[x-1][y]) { // 좌
        count = DFS(x-1, y, count);
    }
    if (isValid(x+1, y) && graph[x+1][y] && !isVisited[x+1][y]) { // 우
        count = DFS(x+1, y, count);
    }

    return count;
}

int main() {
    int k;
    cin >> m >> n >> k;

    for (int j = 0; j < k; j++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = true;
    }

    int value = 0;
    for (int a = 1; a <= m; a++) {
        for (int b = 1; b <= n; b++) {
            if (graph[a][b] && !isVisited[a][b]) {
                value = max(DFS(a, b, 0), value);
            }
        }
    }
    
    cout << value << endl;
    return 0;
}