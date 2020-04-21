#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
long long N;
string answer = "bad puzzle";

vector<long long> adj;
vector<long long> answerAdj;

long long startIdx = 0, endIdx;

// 밀었을 때 답인지
bool isPushEqual() {
	long long idx = 0;

	for (long long i = startIdx;i < endIdx; i++) {
		if (adj[i%N] != answerAdj[idx])
			return false;

		idx++;
	}
	return true;
}

// 뒤집었을 떄 답인지
bool isReverseEqual() {
	long long idx = 0;
	for (long long i = endIdx-1;i >= startIdx; i--) {
		if (adj[i%N] != answerAdj[idx])
			return false;

		idx++;
	}
	return true;

}

int main() {	
	cin >> N;

	for (long long i = 0;i < N;i++) {
		long long num;
		cin >> num;
		adj.push_back(num);
	}

	for (long long i = 0;i < N;i++) {
		long long num;
		cin >> num;
		answerAdj.push_back(num);
	}
	
	endIdx = N;
	if (isPushEqual()) {
		answer = "good puzzle";
	}

	else {
		for (long long i = 0;i < N;i++) {
			// 밀기 -> 인덱스로만 -> startIdx%N **
			startIdx++;
			endIdx++;
			
			// 민 결과 데이터가 답 인지
			if (isPushEqual()) {
				answer = "good puzzle";
				break;
			}

			// 민걸 뒤집었을 때 결과가 답인지
			if (isReverseEqual()) {
				answer = "good puzzle";
				break;
			}
		}
	}

	cout << answer;

	return 0;
}
