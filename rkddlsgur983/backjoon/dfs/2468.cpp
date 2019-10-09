// BOJ DFS 2468 안전 영역
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int graph[100][100];
bool isVisited[100][100];
int n;

// 상하좌우 확인 시 배열 범위 안인지 확인
bool isValid(int x, int y) {

    if (x < 0 || x >= n) {
        return false;
    }
    if (y < 0 || y >= n) {
        return false;
    }
    return true;
}

int DFS(int h, int x, int y) {

    // 노드 방문
    isVisited[x][y] = true;
    
    if (isValid(x, y-1) && graph[x][y-1] > h && !isVisited[x][y-1]) { // 상
        DFS(h, x, y-1);
    }
    if (isValid(x, y+1) && graph[x][y+1] > h && !isVisited[x][y+1]) { // 하
        DFS(h, x, y+1);
    }
    if (isValid(x-1, y) && graph[x-1][y] > h && !isVisited[x-1][y]) { // 좌
        DFS(h, x-1, y);
    }
    if (isValid(x+1, y) && graph[x+1][y] > h && !isVisited[x+1][y]) { // 우
        DFS(h, x+1, y);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // 그래프의 최대값 추출
    int max_value = 0;
    for (int i = 0; i < n; i++) {
        max_value = max(*max_element(graph[i], graph[i] + n), max_value);
    }

    int max_area = 1;
    // 높이 1부터 그래프 최대 높이까지 DFS 반복
    for (int h = 1; h <= max_value; h++) {
        memset(isVisited, false, sizeof(isVisited));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] > h && !isVisited[i][j]) {
                    DFS(h, i, j);
                    cnt += 1;
                }
            }
        }
        max_area = max(cnt, max_area);
    }

    cout << max_area;
    return 0;
}