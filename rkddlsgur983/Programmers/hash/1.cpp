/* 완주하지 못한 선수
 * 2019.10.20
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < completion.size(); i++) {
        if (completion[i].compare(participant[i]) != 0) {
            return participant[i];
        }
    }
    return participant[participant.size()-1];
}

string solution2(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> strMap;
    for (auto elem: completion) {
        if (strMap.end() == strMap.find(elem)) {
            strMap.insert(make_pair(elem, 1));
        } else {
            strMap[elem]++;
        }
    }

    for (auto elem: participant) {
        if (strMap.end() == strMap.find(elem)) {
            return elem;
        } else {
            strMap[elem]--;
            if (strMap[elem] < 0) {
                return elem;
            }
        }
    }
}