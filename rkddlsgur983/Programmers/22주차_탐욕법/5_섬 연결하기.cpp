/* 섬 연결하기
 * 2020.01.19
 */
#include <algorithm>
#include <vector>

using namespace std;

int graph[101][101];
bool visited[101];
int minCost = 100000;

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

void DFS(int a, int b, int n, int cost) {

    if (a == b) {
        minCost = min(minCost, cost);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (graph[a][i] != 0 && visited[i] == false) {
            visited[i] = true;
            DFS(i, b, n, graph[a][i]);
            visited[i] = false;
        }
    }
}

int possible(int a, int b, int n, vector<vector<int>> costs) {

    visited[a] = true;
    for (int i = 0; i < n; i++) {
        if (graph[a][i] != 0 && visited[i] == false) {
            visited[i] = true;
            DFS(i, b, n, graph[a][i]);
            visited[i] = false;
        }
    }
    visited[a] = false;
    int cost = minCost;
    minCost = 100000;
    return cost;
}

int solution(int n, vector<vector<int>> costs) {

    int answer = 0;
    // 비용 순 오름차순
    sort(costs.begin(), costs.end(), compare);
    for (int i = 0; i < costs.size(); i++) {
        /* a에서 b까지 비용이 현재까지 생성된
         * 그래프의 값보다 작은 경우 그래프에 추가
         */
        int value = possible(costs[i][0], costs[i][1], n, costs);
        if (value > costs[i][2]) {
            graph[costs[i][0]][costs[i][1]] = costs[i][2];
            graph[costs[i][1]][costs[i][0]] = costs[i][2];
            answer += costs[i][2];
        }
    }
    return answer;
}