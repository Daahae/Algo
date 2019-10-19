// BOJ 12100 2048
// 완전탐색 dfs
// 2019.10.17
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int n;
int max_value;

void left(int graph[20][20]) {

    for (int i = 0; i < n; i++) {

        // 왼쪽으로 밈
        vector<int> num;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] > 0) {
                num.push_back(graph[i][j]);
            }
        }
        memset(graph[i], 0, sizeof(graph[i]));
        for (int j = 0; j < num.size(); j++) {
            graph[i][j] = num[j];
        }

        // 같은 값이면 더함
        for (int j = 0; j < n-1; j++) {
            if (graph[i][j] != 0 && graph[i][j] == graph[i][j+1]) {
                graph[i][j] *= 2;
                int k = j+1;
                while (k < n-1) {
                    if (graph[i][k+1] != 0) {
                        graph[i][k] = graph[i][k+1];
                    } else {
                        break;
                    }
                    k++;
                }
                graph[i][k] = 0;
            }
        }
    }
}

void right(int graph[20][20]) {

    for (int i = 0; i < n; i++) {
        // 오른쪽으로 밈
        vector<int> num;
        for (int j = n-1; j >= 0; j--) {
            if (graph[i][j] > 0) {
                num.push_back(graph[i][j]);
            }
        }
        memset(graph[i], 0, sizeof(graph[i]));
        for (int j = 0; j < num.size(); j++) {
            graph[i][n-1-j] = num[j];
        }

        // 같은 값이면 더함
        for (int j = n-1; j >= 1; j--) {
            if (graph[i][j] != 0 && graph[i][j] == graph[i][j-1]) {
                graph[i][j] *= 2;
                int k = j-1;
                while (k > 0) {
                    if (graph[i][k-1] != 0) {
                        graph[i][k] = graph[i][k-1];
                    } else {
                        break;
                    }
                    k--;
                }
                graph[i][k] = 0;
            }
        }
    }
}

void up(int graph[20][20]) {
    
    int temp[20][20] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][i] = graph[i][j];
        }
    }
    left(temp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[j][i] = temp[i][j];
        }
    }
}

void down(int graph[20][20]) {
    
    int temp[20][20] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][i] = graph[i][j];
        }
    }
    right(temp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[j][i] = temp[i][j];
        }
    }
}

void DFS(int cnt, int graph[20][20]) {
    if (cnt == 5) {
        for (int i = 0; i < n; i++) {
            max_value = max(max_value, *max_element(graph[i], graph[i]+n));
        }
        return;
    }

    int left_temp[20][20] = {0};
    copy(&graph[0][0], &graph[0][0] + 20*20, &left_temp[0][0]);
    left(left_temp);
    DFS(cnt+1, left_temp);

    int right_temp[20][20] = {0};
    copy(&graph[0][0], &graph[0][0] + 20*20, &right_temp[0][0]);
    right(right_temp);
    DFS(cnt+1, right_temp);

    int up_temp[20][20] = {0};
    copy(&graph[0][0], &graph[0][0] + 20*20, &up_temp[0][0]);
    up(up_temp);
    DFS(cnt+1, up_temp);

    int down_temp[20][20] = {0};
    copy(&graph[0][0], &graph[0][0] + 20*20, &down_temp[0][0]);
    down(down_temp);
    DFS(cnt+1, down_temp);
}

int main() {
    cin >> n;

    int graph[20][20] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    DFS(0, graph);

    cout << max_value;
    return 0;
}