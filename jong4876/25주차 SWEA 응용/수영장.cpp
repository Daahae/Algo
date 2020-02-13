
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dp[13]; // 일, 달 기준 dp
int minDp[13]; // 일, 달, 3달, year 기준 dp

void dfs(int bill[4], int month[13]) {

	int dayBill = bill[0], monthBill = bill[1], TmonthBill = bill[2], yearBill = bill[3];

	// day, month 요금비교 후 최솟값 dp저장
	for (int i = 1;i <= 12;i++)
		dp[i] = min(dayBill*month[i], monthBill);
	

	// i달까지 지났을 때 발생하는 최소의 금액 minDp ***
	for (int i = 1;i <= 12;i++) {
		minDp[i] = minDp[i - 1] + dp[i];

		//3개월권을 쓸 수 있는 달이라면
		if (i >= 3) {
			minDp[i] = min(minDp[i], minDp[i - 3] + TmonthBill);
		}
	}

	// 1년권 비교
	minDp[12] = min(minDp[12], yearBill);

}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int month[13];
		int bill[4];

		// 1일, 1달, 3달, 1년
		for (int i = 0;i < 4;i++)
			cin >> bill[i];

		for (int i = 1;i <= 12;i++) {
			cin >> month[i];
			dp[i] = 0;
			minDp[i] = 0;
		}

		dfs(bill, month);
		
		cout << "#" << test_case << " " << minDp[12] << endl;
	}
	return 0;
}