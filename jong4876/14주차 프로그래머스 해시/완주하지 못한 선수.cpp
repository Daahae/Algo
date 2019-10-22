#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> marathonMap;


	for (int i = 0;i < participant.size(); i++)
		marathonMap[participant[i]] = 0;

	for (int i = 0;i < participant.size(); i++)
		marathonMap[participant[i]]--;


	for (int i = 0;i < completion.size(); i++)
		marathonMap[completion[i]]++;

	for (int i = 0;i < participant.size(); i++)
		cout <<participant[i]<< " : "<< marathonMap[participant[i]]<<endl;


	for (int i = 0;i < participant.size(); i++) {
		if (marathonMap[participant[i]] < 0) {
			answer = participant[i];
		}
	}
	return answer;

}