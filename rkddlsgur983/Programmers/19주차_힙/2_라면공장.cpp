/* 라면공장
 * 2019.10.26
 */
#include <queue>
#include <vector>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    
    priority_queue<int, vector<int>, less<int>> pq;
    int answer = 0;
    int index = 0;
    while (stock < k) {
        while (index < dates.size() && dates[index] <= stock) {
            pq.push(supplies[index]);
            index += 1;
        }
        stock += pq.top();
        pq.pop();
        answer += 1;
    }
    return answer;
}