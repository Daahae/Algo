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
	
	sort(rectangle.begin(), rectangle.end()); // �ε��� ������ ����

	for (int i = 0; i < N; i++) {
		if (maxHeight < rectangle[i].second) {
			maxHeight = rectangle[i].second;
			maxIdx = i;
		}
	}
	/* �� ���븸 push �ϰ� �������� pop�ϴ�����, �������� �ϴٰ��*/


	// �ִ� ������ġ���� ������ ���ε�������
	s.push(rectangle[maxIdx]);
	for (int i = maxIdx+1; i <N;i++) { 
		if (s.empty())
			s.push(rectangle[i]);
			
		else if(s.top().second < rectangle[i].second) { // ���������϶�
			while (s.top().second < rectangle[i].second) {
				s.pop();
			}
			s.push(rectangle[i]); // �� ���������� ����
		}
		else { // ���������϶�
			s.push(rectangle[i]);
		}
	}
	
	while (s.size()>1) { // pop�ذ��鼭 ���� ��� 1������������
		int row, col;
		col = s.top().second;
		row = s.top().first;
		s.pop();
		row -= s.top().first;
		sumWidth += (row * col);
	}

	while(!s.empty())
		s.pop();



	// �ִ� ������ġ���� ���� ���ε�������
	s.push(rectangle[maxIdx]);
	for (int i = maxIdx - 1; i >= 0;i--) {
		if (s.empty())
			s.push(rectangle[i]);

		else if (s.top().second < rectangle[i].second) { // ���������϶�
			while (s.top().second < rectangle[i].second) {
				s.pop();
			}
			s.push(rectangle[i]); // �� ���������� ����
		}
		else { // ���������϶�
			s.push(rectangle[i]);
		}
	}

	while (s.size()>1) { // pop�ذ��鼭 ���� ��� 1������������
		int row, col;
		col = s.top().second;
		row =(-1)*s.top().first;
		s.pop();
		row += s.top().first;
		sumWidth += (row * col);
	}
	while (!s.empty())
		s.pop();

	sumWidth += rectangle[maxIdx].second; // ��� ����

	cout << sumWidth;


	return 0;
}