/* 단어변환
 * 2019.12.28
 */
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int cnt = 51;
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

void DFS(string begin, string target, vector<string> words, int count) {

    if (begin.compare(target) == 0) {
        cnt = min(cnt, count);
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (!visited[i] && transformation(begin, words[i])) {
            visited[i] = true;
            DFS(words[i], target, words, count+1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    for (int i = 0; i < words.size(); i++) {
        if (transformation(begin, words[i])) {
            visited[i] = true;
            DFS(words[i], target, words, 1);
            visited[i] = false;
        }
    }
    int answer = (cnt == 51) ? 0 : cnt;
    return answer;
}