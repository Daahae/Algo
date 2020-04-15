#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;

int main() {
	int N, P;
	stack<int> s[7];

	cin >> N >> P;

	int moveCnt = 0;

	for (int i = 0;i < N;i++) {
		int lineNum, plat;
		cin >> lineNum >> plat;
		
		// 아무손도 안누르고 있을 떄
		if (s[lineNum].empty()) {
			s[lineNum].push(plat);
			moveCnt++;
		}

		else {
			// 손을 누르기만 하면 되는 상황
			if (s[lineNum].top() < plat) {
				s[lineNum].push(plat);
				moveCnt++;
			}

			// 손을 때야될 상황
			else if (s[lineNum].top() > plat) {
				
				while (!s[lineNum].empty() && s[lineNum].top() > plat) {
					s[lineNum].pop();
					moveCnt++;
				}

				// 이미 눌러있는 상태인 경우 **
				if (s[lineNum].empty() || s[lineNum].top() != plat) {
					s[lineNum].push(plat);
					moveCnt++;
				}
			}
		}
	}
	cout << moveCnt;



	return 0;
}
