#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;
int N;
long long answer = 0;

// 숫자 벡터
vector<int> numVec;
// 수식 벡터
vector<char> calVec;

long long calCulate(long long num1, long long num2, char cal) {
	if (cal == '+')
		return num1 + num2;
	else if (cal == '-')
		return num1 - num2;
	else
		return num1 * num2;

}

// 괄호가 붙는 모든 경우에 대하여 DFS
void DFS(long long result, int idx) {
	if (idx >= calVec.size()) {
		if (answer < result)
			answer = result;

		return;
	}
	//cout << result <<endl;
	// 정방향 계산
	long long res = calCulate(result, numVec[idx + 1], calVec[idx]);
	DFS(res, idx+1);

	// 역방향으로 계산, 괄호 나누기
	if (idx+1 < calVec.size()) {
		long long res2 = calCulate(numVec[idx + 2], numVec[idx +1], calVec[idx +1]);

		// 정방향, 역방향, 괄호의 결과값 계산
		long long res3 = calCulate(result, res2, calVec[idx]);
		DFS(res3, idx + 2);
	}

}

int main() {

	string str;
	cin >> N;
	cin >> str;

	// +,-먼저 *나중?
	// 숫자 연산 나누어서 저장
	for (int i = 0;i < N;i++) {
		if ('0' <= str[i] && str[i] <= '9')
			numVec.push_back(str[i] - '0');

		else
			calVec.push_back(str[i]);
	}

	DFS(numVec[0], 0);

	cout << answer;

	return 0;
}
