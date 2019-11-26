/* 모의고사
 * 2019.10.26
 */
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> p[3];
    p[0] = vector<int>({1,2,3,4,5});
    p[1] = vector<int>({2,1,2,3,2,4,2,5});
    p[2] = vector<int>({3,3,1,1,2,2,4,4,5,5});
    
    vector<int> cnt(3);
    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (p[j][i%p[j].size()] == answers[i]) {
                cnt[j] += 1;
            }
        }
    }

    int max_index = *max_element(cnt.begin(), cnt.end());
    vector<int> answer;
    for (int i = 0; i < 3; i++) {
        if (max_index == cnt[i]) {
            answer.push_back(i+1);
        }
    }
    return answer;
}