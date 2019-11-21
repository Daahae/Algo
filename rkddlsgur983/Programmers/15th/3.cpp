/* 디스크 컨트롤러
 * 65.0 / 100.0
 * 2019.11.20
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

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push(jobs[0]);
    int answer = 0;
    int time = jobs[0][0];
    jobs.erase(jobs.begin());

    while(!pq.empty()) {
        time += pq.top()[1];
        answer += time-pq.top()[0];
        pq.pop();

        while (!jobs.empty() && jobs[0][0] <= answer) {
            pq.push(jobs[0]);
            jobs.erase(jobs.begin());
        }
        if (pq.empty() && !jobs.empty()) {
            pq.push(jobs[0]);
            jobs.erase(jobs.begin());
        }
    }
    return answer / size;
}

int main() {
    vector<vector<int>> jobs;
    jobs.push_back({0, 3});
    jobs.push_back({1, 9});
    jobs.push_back({2, 6});
    
    cout << solution(jobs); // 9
    return 0;
}