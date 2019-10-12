// BOJ BFS 1260 DFS와 BFS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[1001];

bool dfs_visited[1001];
bool bfs_visited[1001];

void DFS(int start) {

    dfs_visited[start] = true;
    cout << start << ' ';

    for (int j = 0; j < graph[start].size(); j++) {
        int next = graph[start][j];
        if (!dfs_visited[next]) {
            DFS(next);
        }
    }
}

void BFS(int start) {

    queue<int> q;
    bfs_visited[start] = true;

    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs_visited[node] = true;
        cout << node << ' ';

        for (int j = 0; j < graph[node].size(); j++) {
            int next = graph[node][j];
            if (!bfs_visited[next]) {            
                bfs_visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    int node1, node2;
    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;
        graph[node1].push_back(node2); // 양방향 연결
        graph[node2].push_back(node1);
    }

    for (int i = 1; i <= 1000; i++) {
        // 작은 정점부터 방문하기 위한 정렬
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(v);
    cout << endl;
    BFS(v);

    return 0;
}