#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	sort(times.begin(), times.end());

	// 처음에 심사받는 사람 제외하고 시작
	n -= times.size();

	long long presentTime = times[times.size() - 1];

	while (1) {

		for (int i = 0;i < times.size();i++) {
			if (presentTime% times[i] == 0) {
				n--;
				if (n == 0) {
					presentTime += times[i];
				}
					

				break;
			}
		}
	
		
		presentTime++;
	}
	answer = presentTime;

	return answer;
}