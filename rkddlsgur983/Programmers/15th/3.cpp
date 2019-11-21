/* 디스크 컨트롤러
 * 2019.11.22
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {

    int size = jobs.size();
    sort(jobs.begin(), jobs.end(), compare);

    int time = jobs[0][0] + jobs[0][1];
    int answer = jobs[0][1]; // 요청부터 종료까지 걸린 시간
    jobs.erase(jobs.begin());

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    while (!jobs.empty() || !pq.empty()) {
        while (!jobs.empty() && jobs[0][0] <= time) {
            pq.push(jobs[0]);
            jobs.erase(jobs.begin());
        }
        
        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time-pq.top()[0];
            pq.pop();
        } else if (!jobs.empty() && jobs[0][0] > time) {
            time = jobs[0][0] + jobs[0][1];
            answer += jobs[0][1];
            jobs.erase(jobs.begin());
        }
    }
    return answer / size;
}

int main() {
    vector<vector<int>> jobs({{0, 3}, {1, 9}, {2, 6}});
    cout << solution(jobs); // 9
    return 0;
}