#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <sstream>
#include <stack>

using namespace std;
long long maxWidth = -1;
long long baseHeight;
stack<long long> s;

long long getMaxWidth() { // 스택안에있는 것들의 최대넓이 구하기 & pop all
	long long minHeight;
	long long mWidth = -1;
	long long size = s.size();
	int j;

	minHeight = s.top();
	for (j = 1;j <= size;j++) { // 포문에 가변길이 넣치말것 실수원인
		if (minHeight > s.top()) {
			minHeight = s.top();
		}
	
		long long width = minHeight * j;      
		if (mWidth < width)
			mWidth = width;
		
		s.pop();
	}
	return mWidth;
}

int main() {
	long N;
	int i;
	long long tmp;	
	vector <long long> rectangle;

	cin >> N;
	for (i = 0;i < N;i++) { 
		cin >> tmp;
		if (i == 0)
			baseHeight = tmp;

		rectangle.push_back(tmp);
		if (tmp < baseHeight) // 높이의 최소값
			baseHeight = tmp;
	}
	maxWidth = baseHeight * N;
	//cout << "?? :" << baseHeight << endl;

	for (i = 0;i < N;i++) { // 최소 최소값*N이상
		long long compareHeight = rectangle[i]; // 비교할 현재 높이값
		if (s.empty() || (rectangle[i] != baseHeight)) { // 오르막길일때 push
			s.push(rectangle[i]);
		}
		else {// 내리막일때 넓이 계산 후 전부 pop
			long long result = getMaxWidth();
			if (maxWidth < result)
				maxWidth = result;
		}
	}

	if (s.size() != 0) {
		long long result = getMaxWidth();
		if (maxWidth < result)
			maxWidth = result;
	}
	

	cout << maxWidth;


	return 0;
}