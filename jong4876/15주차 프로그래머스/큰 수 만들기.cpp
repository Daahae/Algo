#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(char a, char b) {
	return a > b;
}

string solution(string number, int k) {
	string answer = "";
	vector<char> stringNum;
	vector<int> intIdx;

	for (int i = 0;i < number.length();i++)
		stringNum.push_back(number[i]);

	sort(stringNum.begin(), stringNum.end());

	for (int i = 0;i < stringNum.size();i++)
		cout << stringNum[i] << endl;
		
	int cnt = 0;
	while (1) {
		if (k == 0)
			break;
		for (int i = 0;i < number.length();i++) {
			if (stringNum[cnt] == number[i]) {
				number.erase(number.begin() + i);		
				k--;
				if (k == 0)
					break;
			}
		}
		cnt++;
	}
	for (int i = 0;i < number.length();i++)
		answer += number[i];

	

	return answer;
}