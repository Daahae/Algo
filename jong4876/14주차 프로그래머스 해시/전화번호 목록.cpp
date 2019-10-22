#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	

	for (int i = 0;i < phone_book.size();i++) {
		string destPhone;
		destPhone = phone_book[i];

		for (int j = 0;j < phone_book.size();j++) {
			int flag  = 1;
			if (i == j)
				continue;

			if (destPhone.length() > phone_book[j].length())
				continue;

			for (int k = 0;k < destPhone.length();k++) {
				if (destPhone[k] != phone_book[j][k]) {
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				return false;
		}
	}


	return answer;
}