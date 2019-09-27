#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <algorithm>


using namespace std;


int main(){
	int N;
	vector <pair<int, int>> rectangle;
	stack<pair<int, int>> s;
	int maxHeight = -1;
	int maxIdx;
	long long sumWidth = 0;

	cin >> N;

	for (int i = 0;i < N;i++) {
		int row, height;
		cin >> row >> height;
		rectangle.push_back(pair<int, int>(row,height));
	}
	
	sort(rectangle.begin(), rectangle.end()); // 인덱스 단위로 정렬

	for (int i = 0; i < N; i++) {
		if (maxHeight < rectangle[i].second) {
			maxHeight = rectangle[i].second;
			maxIdx = i;
		}
	}
	/* 쓸 막대만 push 하고 나머지는 pop하는형식, 마지막에 싹다계산*/


	// 최대 높이위치에서 오른쪽 끝인덱스까지
	s.push(rectangle[maxIdx]);
	for (int i = maxIdx+1; i <N;i++) { 
		if (s.empty())
			s.push(rectangle[i]);
			
		else if(s.top().second < rectangle[i].second) { // 오르막길일때
			while (s.top().second < rectangle[i].second) {
				s.pop();
			}
			s.push(rectangle[i]); // 더 높은값으로 갱신
		}
		else { // 내리막길일때
			s.push(rectangle[i]);
		}
	}
	
	while (s.size()>1) { // pop해가면서 넓이 계산 1개남을때까지
		int row, col;
		col = s.top().second;
		row = s.top().first;
		s.pop();
		row -= s.top().first;
		sumWidth += (row * col);
	}

	while(!s.empty())
		s.pop();



	// 최대 높이위치에서 왼쪽 끝인덱스까지
	s.push(rectangle[maxIdx]);
	for (int i = maxIdx - 1; i >= 0;i--) {
		if (s.empty())
			s.push(rectangle[i]);

		else if (s.top().second < rectangle[i].second) { // 오르막길일때
			while (s.top().second < rectangle[i].second) {
				s.pop();
			}
			s.push(rectangle[i]); // 더 높은값으로 갱신
		}
		else { // 내리막길일때
			s.push(rectangle[i]);
		}
	}

	while (s.size()>1) { // pop해가면서 넓이 계산 1개남을때까지
		int row, col;
		col = s.top().second;
		row =(-1)*s.top().first;
		s.pop();
		row += s.top().first;
		sumWidth += (row * col);
	}
	while (!s.empty())
		s.pop();

	sumWidth += rectangle[maxIdx].second; // 가운데 막대

	cout << sumWidth;


	return 0;
}