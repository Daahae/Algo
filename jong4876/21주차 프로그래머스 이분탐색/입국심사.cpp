#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	sort(times.begin(), times.end());
	answer = times[0];


	while (1) {
		long long cnt = 0;

		// answer시간에 심사원들이 감당할 수 있는 최대 명수 == n 일 때 종료
		for (int i = 0;i < times.size();i++) 
			cnt += answer / times[i];
		
		if (cnt == n)
			break;

		answer++;
	}



	return answer;
}
