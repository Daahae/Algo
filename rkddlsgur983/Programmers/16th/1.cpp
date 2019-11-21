/* 순위
 * 2019.11.20
 */
#include <iostream>
#include <vector>

using namespace std;

int graph[101][101];

int solution(int n, vector<vector<int>> results) {
    
    for (auto r: results) {
        graph[r[0]][r[1]] = 1; // 이긴 경우
        graph[r[1]][r[0]] = 2; // 진 경우
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                } else if (graph[i][k] == 2 && graph[k][j] == 2) {
                    graph[i][j] = 2;
                }
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] != 0) {
                cnt++;
            }
        }
        if (cnt == n-1) {
            answer++;
        }
    }
    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> results;
    results.push_back({4, 3});
    results.push_back({4, 2});
    results.push_back({3, 2});
    results.push_back({1, 2});
    results.push_back({2, 5});
    
    cout << solution(n, results); // 2
    return 0;
}