// BOJ DFS 10265 MT
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

const int MAX_N = 1001;

// DFS
vector<int> graph[MAX_N];
bool isVisited[MAX_N];

// DP
int group[MAX_N], dp[MAX_N];

int DFS(int node, int cnt) {

    // 노드 방문
    isVisited[node] = true;
    cnt += 1;
    
    for (int j = 0; j < graph[node].size(); j++) {
        int next = graph[node][j];
        // 방문한 노드가 아니면 탐색    
        if (!isVisited[next]) {
            cnt = DFS(next, cnt);
        }
    }
    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;

    int node;
    for (int i = 1; i <= n; i++) {
        cin >> node;
        graph[i].push_back(node);
        graph[node].push_back(i);
    }

    int group_cnt = 0;
    // 순차 노드 방문
    for (int i = 1; i <= n; i++) {
        // 방문 노드가 아니면 탐색
        // 그래프의 노드 개수 저장
        int cnt = 0;
        if (!isVisited[i]) {
            cnt = DFS(i, cnt);
        }
        // cnt: DFS로 구현된 각 그래프에 속한 노드의 개수
        // group[]: DP를 위한 배열
        // group_cnt: DFS로 구현된 그래프 수
        if (cnt > 0) {
            group[group_cnt] = cnt;
            group_cnt += 1;
        }
    }

    // DP 배열 오름차순 정렬
    sort(group, group+group_cnt);
    
    /* DP
     * k를 넘지않는 최대 인원수
     */
    dp[0] = group[0];
    for (int i = 0; i < group_cnt; i++) {
        if (k == dp[i-1] + group[i]) {
            cout << k;
            return 0;
        } else if (k > dp[i-1] + group[i]) {
            dp[i] = dp[i-1] + group[i];
        } else { // k < dp[i-1] + group[i]
            if (k == group[i]) {
                cout << k;
                return 0;
            } else if (k < group[i]) {
                dp[i] = dp[i-1];
            } else { // k > group[i]
                dp[i] = max(dp[i-1], group[i]);
            }
        }
        // dp[i] = (k >= (dp[i-1] + group[i]))
        //         ? dp[i-1] + group[i] : max(dp[i-1], group[i]);
    }

    int max_value = dp[0];
    for (int i = 1; i < group_cnt; i++) {
        if (k == dp[i] && max_value < dp[i]) {
            cout << k;
            return 0;
        } else if (k > dp[i]) {
            if (max_value < dp[i]) {
                max_value = dp[i];
            }
        } else { // k < dp[i]
            break;
        }
    }

    cout << max_value;
    return 0;
}