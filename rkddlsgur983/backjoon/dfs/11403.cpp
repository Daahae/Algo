// BOJ DFS 11403 경로 찾기
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int graph[100][100];
bool isVisited[100];
int n;

void DFS(int start) {

    for (int j = 0; j < n; j++) {
        if (graph[start][j] && !isVisited[j]) {
            isVisited[j] = true;
            DFS(j);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        // 방문여부 초기화
        memset(isVisited, 0, sizeof(isVisited));
        DFS(i);
        for (int j = 0; j < n; j++) {
            cout << isVisited[j] << ' ';
        }
        cout << endl;
    }

    return 0;
}