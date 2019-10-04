// BOJ DFS 11724 연결 요소의 개수
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1001;

vector<int> graph[MAX_N];
bool isVisited[MAX_N]; 

int DFS(int node) {

    // 노드 방문
    isVisited[node] = true;
    
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];

        // 방문한 노드가 아니면 탐색    
        if (!isVisited[next]) {
            DFS(next);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int node1, node2;
    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;
        // 노드 상호 연결
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int cnt = 0;
    // 순차 노드 방문
    for (int i = 1; i <= n; i++) {
        // 방문 노드가 아니면 탐색
        // 연결 요소 +1
        if (!isVisited[i]) {
            DFS(i);
            cnt += 1;
        }
    }

    cout << cnt;
    return 0;
}