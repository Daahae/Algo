/* 네트워크
 */
#include <vector>

using namespace std;

bool isVisited[200];

void DFS(int n, vector<vector<int>> computers, int start) {
    
    isVisited[start] = true;

    for (int j = 0; j < n; j++) {
        if (!isVisited[j] && computers[start][j] == 1) {
            DFS(n, computers, j);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!isVisited[i]) {
            DFS(n, computers, i);
            answer += 1;
        }
    }
    return answer;
}