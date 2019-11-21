/* 땅따먹기
 * 2019.11.11
 */
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int> > land) {
    for (int i = 0; i < land.size()-1; i++) {
        for (int j = 0; j < 4; j++) {
            int m = 0;
            for (int k = 0; k < 4; k++) {
                if (j != k) {
                    m = max(m, land[i][k]);
                }
            }
            land[i+1][j] += m;
        }
    }
    sort(land.back().begin(), land.back().end(), greater<int>());
    int answer = land.back()[0];
    return answer;
}