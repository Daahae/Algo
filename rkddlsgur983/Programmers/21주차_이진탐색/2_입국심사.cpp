/* 입국심사
 * 이분탐색
 * 2020.01.12
 */
#include <algorithm>
#include <vector>

using namespace std;

long long grantedPeople(vector<int> times, long long time) {

    long long people = 0L;
    for (auto t: times) {
        people += time / t;
    }
    return people;
}

long long solution(int n, vector<int> times) {

    sort(times.begin(), times.end());
    // 탐색 범위 0 ~ 가장 오래 걸리는 심사대 * 인원수
    long long low = 0;
    long long high = (long long) times.back()*n; // 명시적 형변환
    long long answer = high;

    while (low <= high) {
        long long mid = (low+high)/2;
        long long people = grantedPeople(times, mid); // mid 시간내에 심사받은 사람들

        if (people < n) {
            low = mid+1;
        } else { // people >= n
            /* grantedPeople의 값이 n보다 클 때 올바른 경우가 있다.
             * time=20, times={4, 10} 인 경우 n의 올바른 범위는 5 ~ 7이다.
             * 이때 n=6인 경우 범위내에 있으므로 정답의 가능성이 있기에 answer에 저장한다. 
             */
            high = mid-1;
            if (answer > mid) {
                answer = mid;
            }
        }
    }
    return answer;
}