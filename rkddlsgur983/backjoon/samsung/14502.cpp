// BOJ 14502 연구소
// 완전탐색 dfs
// 2019.10.16
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int graph[8][8];

int max_safe = 0;

bool isValid(int i, int j) {

    if (i < 0 || i >= n) {
        return false;
    }
    if (j < 0 || j >= m) {
        return false;
    }
    return true;
}

void DFS_Infect(int graph_copy[8][8], bool isVisitedInfect[8][8], int i, int j) {
    
    if (isValid(i, j-1) && graph_copy[i][j-1] == 0 && !isVisitedInfect[i][j-1]) {
        graph_copy[i][j-1] = 2;
        isVisitedInfect[i][j-1] = true;
        DFS_Infect(graph_copy, isVisitedInfect, i, j-1);
    }
    if (isValid(i, j+1) && graph_copy[i][j+1] == 0 && !isVisitedInfect[i][j+1]) {
        graph_copy[i][j+1] = 2;
        isVisitedInfect[i][j+1] = true;
        DFS_Infect(graph_copy, isVisitedInfect, i, j+1);
    }
    if (isValid(i-1, j) && graph_copy[i-1][j] == 0 && !isVisitedInfect[i-1][j]) {
        graph_copy[i-1][j] = 2;
        isVisitedInfect[i-1][j] = true;
        DFS_Infect(graph_copy, isVisitedInfect, i-1, j);
    }
    if (isValid(i+1, j) && graph_copy[i+1][j] == 0 && !isVisitedInfect[i+1][j]) {
        graph_copy[i+1][j] = 2;
        isVisitedInfect[i+1][j] = true;
        DFS_Infect(graph_copy, isVisitedInfect, i+1, j);
    }
}

void DFS_Empty(int cnt, bool isVisitedEmpty[8][8]) {

    if (cnt == 3) {
        int graph_copy[8][8];
        copy(&graph[0][0], &graph[0][0] + 8*8, &graph_copy[0][0]);
        bool isVisitedInfect[8][8] = {false};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph_copy[i][j] == 2 && !isVisitedInfect[i][j]) {
                    isVisitedInfect[i][j] = true;
                    DFS_Infect(graph_copy, isVisitedInfect, i, j);
                }
            }
        }
        int safe = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph_copy[i][j] == 0) {
                    safe += 1;
                }
            }
        }
        max_safe = max(max_safe, safe);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0 && !isVisitedEmpty[i][j]) {
                graph[i][j] = 1;
                isVisitedEmpty[i][j] = true;
                DFS_Empty(cnt+1,isVisitedEmpty);
                isVisitedEmpty[i][j] = false;
                graph[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    bool isVisitedEmpty[8][8] = {false};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0 && !isVisitedEmpty[i][j]) {
                graph[i][j] = 1;
                isVisitedEmpty[i][j] = true;
                DFS_Empty(1, isVisitedEmpty);
                graph[i][j] = 0;
            }
        }
    }
    cout << max_safe;
    return 0;
}