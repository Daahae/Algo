#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp1[1000001];// 처음 집을 터는경우
int dp2[1000001]; // 처음 집 안터는 경우

int solution(vector<int> money) {
	int answer = 0;


	dp1[0] = money[0];
	dp1[1] = money[0]; // 처음집 털면 마지막 집 못텀

	dp2[0] = 0;
	dp2[1] = money[1];
	// 처음집을 안털면 마지막집 털수 있음
	// 첫집을 안턴다고 2번째를 꼭 털필요도 없음 ** [5,2,9]

	for (int i = 2;i < money.size();i++) {
		dp1[i] = max(money[i] + dp1[i - 2], dp1[i - 1]);
	}

	for (int i = 2;i < money.size();i++) {
		dp2[i] = max(money[i] + dp2[i - 2], dp2[i - 1]);
	}

	int maxVal = max(dp1[money.size() - 2], dp2[money.size() - 1]);
	// dp1 : 처음 집 털면 마지막 집 터는 경우는 뺴야되서 -2
	// dp2 : 마지막 집 터는게 가능해서 -1

	return maxVal;
}
