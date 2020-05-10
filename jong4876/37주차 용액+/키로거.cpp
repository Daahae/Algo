#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int N;
	cin >> N;

	// 해시테이블처럼
	for (int k = 0;k < N;k++) {
		string str;
		int cursorIdx = 0;
		int strLength = 0;
		stack<char> s1;
		stack<char> s2;

		cin >> str;


		for (int i = 0;i < str.length();i++) {
			char order = str[i];
			if (order == '<') {
				if (!s1.empty()) {
					char tmp = s1.top();
					s1.pop();
					s2.push(tmp);
				}
			}
			else if (order == '>') {
				if (!s2.empty()) {
					char tmp = s2.top();
					s2.pop();
					s1.push(tmp);
				}
			}
			else if (order == '-') {
				if (!s1.empty())
					s1.pop();
			}
			else 
				s1.push(order);	
		}
		// 거꾸로 만드는 과정
		while (!s1.empty()) {
			char tmp = s1.top();
			s1.pop();
			s2.push(tmp);
		}
		while (!s2.empty()) {
			cout << s2.top();
			s2.pop();
		}
		cout << endl;
	}
	
	return 0;
}