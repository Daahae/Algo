#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}


vector<string> solution(vector<string> record) {
	vector<string> answers;
	vector<string> action; // 행동은 변하지 않음
	map<string, string> nicknameMap;

	for (int i = 0;i < record.size();i++) { // 닉네임 갱신 먼저
		vector<string> recordWord = split(record.at(i), ' ');	
			if (recordWord.at(0).compare("Enter") == 0) {// Enter
				nicknameMap[recordWord.at(1)] = recordWord.at(2);
			}
			else if (recordWord.at(0).compare("Change") == 0) {
				nicknameMap[recordWord.at(1)] = recordWord.at(2);
			}
	}

	for (int i = 0;i < record.size();i++) { // 닉네임 갱신 먼저
		vector<string> recordWord = split(record.at(i), ' ');
		string answer;

		if (recordWord.at(0).compare("Enter") == 0) {
			string tmpNickname;
			tmpNickname.assign(nicknameMap.at(recordWord.at(1))); // 매핑 값 가져오기
			answer.assign(tmpNickname+"님이 들어왔습니다.");
			answers.push_back(answer);
		}
		else if (recordWord.at(0).compare("Leave") == 0) {
			string tmpNickname;
			tmpNickname.assign(nicknameMap.at(recordWord.at(1))); // 매핑 값 가져오기
			answer.assign(tmpNickname + "님이 나갔습니다.");
			answers.push_back(answer);
		}
	}
	for (int i = 0;i < answers.size();i++) {
		cout << answers.at(i) << endl;
	}

	return answers;
}