/* 단속카메라
 * 2020.01.19
 */
#include <algorithm>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

int solution(vector<vector<int>> routes) {
    
    sort(routes.begin(), routes.end(), compare);
    int answer = 1;
    int in = routes[0][0];
    int out = routes[0][1];
    for (int i = 1; i < routes.size(); i++) {
        if (in < routes[i][0]) {
            out = routes[i][0];
        }
        if (in > routes[i][1]) {
            out = routes[i][1];
        }
        if (in > out) {
            answer += 1;
            in = routes[i][0];
            out = routes[i][1];
        }
    }
    return answer;
}