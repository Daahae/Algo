#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> vec;
vector<int> dp;
vector<int> reverseDp;
int N;


int main() {

	cin >> N;

	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;

		vec.push_back(num);
		dp.push_back(1);
		reverseDp.push_back(1);
	}

	// 정방향 dp
	for (int i = 0;i < N;i++) {
	
		for (int j = 0;j <= i;j++) {

			// vec[j]가 현 인덱스 값보다 작으면서, 가진 경로의 수는 큰 경우, 현 dp++
			// 이를통해 가장 낮은 기울기의 바이토닉 수열 경로로 갱신 가능
			if (vec[j] < vec[i] && dp[j] >= dp[i]) {
				dp[i]++;
			}
		}
	}

	// 역방향 dp
	for (int i = N-1;i >= 0;i--) {
		for (int j = N-1;j >= i;j--) {
			if (vec[j] < vec[i] && reverseDp[j] >= reverseDp[i]) {
				reverseDp[i]++;
			}
		}
	}

	// 정방향 + 역방향 dp 합 -> 해당 인덱스에서의 최대 바이토닉 부분 수열
	int maxDp =1;
	for (int i = 0;i < N;i++) {

		// 가장 최고 길이가 되는 값 구하기
		if (maxDp < dp[i] + reverseDp[i])
			maxDp = dp[i] + reverseDp[i];
	}

	// 정방향과 역방향이 겹치는 지점 --
	cout << maxDp - 1;

	return 0;
}