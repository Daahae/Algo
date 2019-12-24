#include <string>
#include <vector>
#include <iostream>

using namespace std;

int totalCnt = 0;
int visited[21]; // 0 none visited / 1 visited

void dfs(vector<int> numbers, int target, int idx, int sum) {

	int sum = 0;

	if (sum == target && idx == numbers.size()) {
		totalCnt++;
		return;
	}
	if (idx == numbers.size())
		return;


	
	dfs(numbers, target, idx+1, sum+numbers[idx]);
	dfs(numbers, target, idx+1, sum-numbers[idx]);

}


int solution(vector<int> numbers, int target) {
	
	dfs(numbers, target, 0,0);


	return totalCnt;
}