/* 단어변환
 * BFS
 * 2020.01.01
 */
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool visited[50];

bool transformation(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }
    if (cnt == 1) {
        return true;
    } else {
        return false;
    }
}

int BFS(string begin, string target, vector<string> words) {

    queue<pair<string, int> > q;
    q.push(make_pair(begin, 0));

    while (!q.empty()) {
        string temp = q.front().first;
        int level = q.front().second;
        q.pop();
        if (temp.compare(target) == 0) {
            return level;
        }

        for (int i = 0; i < words.size(); i++) {
            if (!visited[i] && transformation(words[i], temp)) {
                visited[i] = true;
                q.push(make_pair(words[i], level+1));
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = BFS(begin, target, words);
    return answer;
}