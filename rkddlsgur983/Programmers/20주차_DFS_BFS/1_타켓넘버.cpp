/* 타겟 넘버
 */
#include <vector>

using namespace std;

int cnt;

void DFS(vector<int> numbers, int target, int value, int i) {
    if (i == numbers.size()) {
        if (value == target) {
            cnt += 1;
        }
        return;
    }
    DFS(numbers, target, value + numbers[i], i+1);
    DFS(numbers, target, value - numbers[i], i+1);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target, 0, 0);
    int answer = cnt;
    return answer;
}