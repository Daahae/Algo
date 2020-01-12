/* 예산
 * 이진탐색
 * 2020.01.12
 */
#include <algorithm>
#include <vector>

using namespace std;

long sumOfBudget(vector<int> budgets, int max_b) {

    long sum = 0L;
    for (auto b: budgets) {
        if (b <= max_b) sum += b;
        else sum += max_b;
    }
    return sum;
}

int solution(vector<int> budgets, int M) {

    sort(budgets.begin(), budgets.end());
    if (sumOfBudget(budgets, budgets.back()) <= M) {
        return budgets.back();
    } 

    // 탐색 범위: 0 ~ 국가 예산 중 가장 큰 값
    int low = 0;
    int high = budgets.back();
    int answer = 0;
    long temp = 0L;

    // mid: 모든 요청이 배정될 수 있는 상한액
    while (low <= high) {
        int mid = (low+high)/2;
        long target = sumOfBudget(budgets, mid);

        if (target == M) {
            return mid;
        } else if (target < M) {
            low = mid+1;
            // 가능한 상한액을 임시 저장
            if (temp < target) {
                temp = target;
                answer = mid;
            }
        } else {
            high = mid-1;
        }
    }
    return answer;
}