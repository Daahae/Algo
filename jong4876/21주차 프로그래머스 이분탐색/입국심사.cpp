#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	sort(times.begin(), times.end());

	long long left = times[0]; // 7
	long long right = 1000000000000000000; // 60?
	long long mid;
	long long cnt = 0;


	while (left < right) {
		cnt = 0;
		mid = (left + right) / 2;
		int flag = 0;

		// answer시간에 심사원들이 감당할 수 있는 최대 명수 == n 일 때 종료 **
		for (long long i = 0;i < times.size();i++) {
			cnt += mid / times[i];

			// 나머지가 0인 값이 있어야 최솟값?
			if (mid%times[i] == 0)
				flag = 1;

		}

		if (cnt == n && flag == 1)
			return mid;

		if (cnt > n)
			right = mid;

		// mid+1 해주는 거 중요 **
		else if (cnt < n)
			left = mid+1;

		// 최솟값에 가깝게 피벗을 이동
		if (cnt == n && flag == 0) {
			left--;
			right--;
		}
	}

	return right;
}
