// BOJ BFS 2644 촌수계산
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[101];

bool bfs_visited[101];

int BFS(int start, int end) {

    queue<pair<int, int> > q; // first: 번호, second: 촌수
    bfs_visited[start] = true;

    q.push(make_pair(start, 0));
    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        bfs_visited[node.first] = true;
        if (end == node.first) {
            return node.second;
        }
        for (int j = 0; j < graph[node.first].size(); j++) {
            int next = graph[node.first][j];
            if (!bfs_visited[next]) {            
                bfs_visited[next] = true;
                q.push(make_pair(next, node.second+1));
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    int start, end;
    cin >> start >> end;

    int m;
    cin >> m;

    int node1, node2;
    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;
        graph[node1].push_back(node2); // 양방향 연결
        graph[node2].push_back(node1);
    }

    cout << BFS(start, end);

    return 0;
}