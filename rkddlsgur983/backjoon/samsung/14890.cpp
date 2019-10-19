// BOJ 14890 경사로
// 2019.10.16
#include <iostream>

using namespace std;

int n, l;
int graph1[100][100], graph2[100][100];

bool isPossible(int i, int graph[100][100]) {
    bool slope[100] = {false};
    for (int j = 0; j < n-1; j++) {
        if (graph[i][j] != graph[i][j+1]) {
            int diff = graph[i][j] - graph[i][j+1];
            if (diff > 1 || diff < -1) {
                return false;
            } else if (diff == 1) {
                int same = 0;
                for (int k = j+1; k < n; k++) {
                    if (graph[i][j+1] == graph[i][k]) {
                        same += 1;
                    } else {
                        break;
                    }
                }
                if (same >= l) {
                    for (int k = 0; k < l; k++) {
                        if (!slope[j+1+k]) {
                            slope[j+1+k] = true;
                        } else {
                            return false;
                        }
                    }
                } else {
                    return false;
                }
            } else { // diff == -1
                int same = 0;
                for (int k = j; k >= 0 ; k--) {
                    if (graph[i][j] == graph[i][k]) {
                        same += 1;
                    } else {
                        break;
                    }
                }
                if (same >= l) {
                    for (int k = 0; k < l; k++) {
                        if (!slope[j-k]) {
                            slope[j-k] = true;
                        } else {
                            return false;
                        }
                    }
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph1[i][j];
            graph2[j][i] = graph1[i][j];
        }
    }

    int path = 0;
    for (int i = 0; i < n; i++) {
        if (isPossible(i, graph1)) {
            path += 1;
        }
        if (isPossible(i, graph2)) {
            path += 1;
        }
    }
    cout << path;
    return 0;
}