/* 더 맵게
 * 2019.10.26
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {

    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int cnt = 0;
    while (pq.size() >= 2 && pq.top() < K) {
        int temp = pq.top();
        pq.pop();
        temp += pq.top()*2;
        pq.pop();
        pq.push(temp);
        cnt += 1;
    }
    if (pq.top() >= K) {
        return cnt;
    } else {
        return -1;
    }
}

int main() {
    vector<int> scoville({1,2,3,9,10,12});
    int K = 7;
    cout << solution(scoville, K); // 2
    return 0;
}