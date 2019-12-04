/* 카드 게임
 * 55.0 / 100.0
 * 2019.11.28
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> left, vector<int> right) {
    int l_max = *max_element(left.begin(), left.end());
    int r_max = *max_element(right.begin(), right.end());

    int answer = 0;
    if (l_max > r_max) {
        for (auto r: right) {
            answer += r;
        }
    } else if (l_max == r_max) {
        int r_index = distance(right.begin(), max_element(right.begin(), right.end()));
        for (int i = 0; i < r_index; i++) {
            answer += right[i];
        }
    } else { // l_max < r_max
        for (auto r: right) {
            if (l_max <= r) {
                break;
            }
            answer += r;
        }
        // 둘다 버리는 경우 추가
    }
    return answer;
}

int main() {
    cout << solution(vector<int>({3,2,5}), vector<int>({2,4,1})) << '\n';
    cout << solution(vector<int>({3,2,5}), vector<int>({2,4,5})) << '\n';
    cout << solution(vector<int>({3,2,5}), vector<int>({2,5,6,1}));
}