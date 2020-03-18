#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<stack>
#include<stdio.h>


using namespace std;

int main() {

	int N;
	// idx, height;
	stack<pair<int, int>> s;

	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		int height;

		scanf("%d", &height);
		if (s.empty()) {
			printf("0 ");
			s.push(make_pair(i + 1, height));
		}

		else {
			// 새로 추가되는 값보다 작은 탑이 스택에 있으면 안된다
			while (!s.empty() && s.top().second <= height)
				s.pop();

			// 왼쪽에 현재보다 큰 탑이 있으면
			if (!s.empty())
				printf("%d ", s.top().first);

			// 없으면
			else
				printf("0 ");

			s.push(make_pair(i + 1, height));
		}
	}

	return 0;
}

