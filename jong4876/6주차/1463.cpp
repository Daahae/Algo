#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int dp[1000000]; // �޸����̼��� ���� �迭

int func(int n) {
	if (n == 1) return 0; // n=1�϶� �������. ���̽����̽�
	if (dp[n] != -1) return dp[n]; // �̹� ����� ���� �׳� ��ȯ

	int cnt = func(n - 1) + 1; // n = 2���� 3,4,5... ��ü��ȯ
	cout << cnt <<":"<< n<<endl;
	if (n % 3 == 0)cnt = min(cnt, func(n / 3) + 1);

	if (n % 2 == 0)cnt = min(cnt, func(n / 2) + 1);

	dp[n] = cnt; // n = 2���� �޸����̼� ���� ���ʷ� ����
	return cnt;
	
}

int main() {
	int N;
	cin >> N;
	fill(dp, dp + 1000000, -1); //-1�� ä��
	cout << func(N);
}


