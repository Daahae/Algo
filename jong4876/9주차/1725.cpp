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

long long getMaxWidth() { // ���þȿ��ִ� �͵��� �ִ���� ���ϱ� & pop all
	long long minHeight;
	long long mWidth = -1;
	long long size = s.size();
	int j;

	minHeight = s.top();
	for (j = 1;j <= size;j++) { // ������ �������� ��ġ���� �Ǽ�����
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
		if (tmp < baseHeight) // ������ �ּҰ�
			baseHeight = tmp;
	}
	maxWidth = baseHeight * N;
	//cout << "?? :" << baseHeight << endl;

	for (i = 0;i < N;i++) { // �ּ� �ּҰ�*N�̻�
		long long compareHeight = rectangle[i]; // ���� ���� ���̰�
		if (s.empty() || (rectangle[i] != baseHeight)) { // ���������϶� push
			s.push(rectangle[i]);
		}
		else {// �������϶� ���� ��� �� ���� pop
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