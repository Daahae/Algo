#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N;
vector < long long > sumVec;


int main() {
	cin >> N; // 5<= N <= 1000
	long long answer = 0;
	int flag = 0;

	
	for (int i = 0;i < N;i++) {
		long long num;
		cin >> num;
		sumVec.push_back(num);
	}
	sort(sumVec.begin(), sumVec.end());

	for (int x =N-1;x >=1 ; x--) {
		answer = sumVec[x];	
		for (int i = x - 1;i >= 0;i--) {

			for (int j = x - 1;j >= 0;j--) {
				long long sum2 = sumVec[i] + sumVec[j];
				if (sum2 > answer) // 그 뒤에는 검사할 필요 없음
					continue;

				for (int k = x - 1;k >= 0;k--) {
					long long sum3 = sumVec[i] + sumVec[j] + sumVec[k];
					if (answer == sum3) {
						cout << answer << endl;
						return 0;
					}
					else if (answer > sum3)
						break;
				}
			}
		}
	}
	
	cout << answer;


	return 0;
}