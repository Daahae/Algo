#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> heightList) {
	int nResult = 0;
	int flag = 0; // 0 감소, 1 증가
	int calculateCnt = 0;
	queue<int> Q;

	for (int i = 0;i < heightList.size();i++) {
		if (Q.empty()) {
			Q.push(heightList[i]);
			continue;
		}

		// 증가일 때 Q안에 있는 너비들 계산
		if (Q.front() <= heightList[i]) { 
			if (Q.size() == 1) {
				Q.pop();
			}
			else { // 스택에 2이상
				int minHeight = min(Q.front(), heightList[i]);
				while (!Q.empty()) {
					if (minHeight - Q.front() > 0)
						nResult += (minHeight - Q.front());
					Q.pop();
				}
			}
		}
		Q.push(heightList[i]);
	}
	return nResult;
}


int main() {
	vector<int> heightList;
	int N;

	cin >> N;

	for (int i = 0;i < N;i++) {
		int tmp;
		cin >> tmp;
		heightList.push_back(tmp);
	}

	cout << solution(heightList)<<endl;

	return 0;
}