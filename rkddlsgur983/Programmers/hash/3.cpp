/* 위장
 * 2019.10.20
 */
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {

    unordered_map<string, int> costume;

    for (auto c: clothes) {
        if (costume.end() == costume.find(c[1])) {
            costume.insert(make_pair(c[1], 1));
        } else {
            costume[c[1]]++;
        }
    }

    int sum = 1;
    for (auto it = costume.begin(); it != costume.end(); it++) {
        sum *= it->second+1;
    }

    int answer = sum-1;
    return answer;
}