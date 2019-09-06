#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;



bool isPrimary(vector<string> tuple) {
	map<string, int> primaryMap; // map�� �ߺ� �˻縦 ��

	for (int i = 0;i < tuple.size();i++) {
		primaryMap[tuple.at(i)] = i;
	}
	if (primaryMap.size() == tuple.size()) // �ߺ����� ������
		return true;

	else
		return false;
}

int solution(vector<vector<string>> relation) {// 2���� ����
	int answer = 0;
	int tupleSize = relation.size(); // 6
	vector<vector<string>> notUniqueRelation;

	for (int j = 0;j < relation.at(0).size();j++) { // 4 ���κ��� ������
		vector<string> tuple;
		for (int i = 0;i < relation.size();i++) { // �ٿ����� �ߺ��˻�? 6
			tuple.push_back(relation.at(i).at(j));
		}
		if (isPrimary(tuple))
			answer++;
		else {
			notUniqueRelation.push_back(tuple); // �ߺ� Ʃ���� ���λ��� �� �����̼�����
		}
	}

	int rowSize = notUniqueRelation.at(0).size(); // 3
	int colSize = notUniqueRelation.size(); // 6

	for (int i = 0;i < colSize;i++) {
		for (int k = 0;k < colSize;k++) {
			if (i >= k)continue;
			cout << i << " : " << k << endl;
			vector<string> tuple;

			for (int j = 0;j < rowSize;j++) { // �ٿ����� �ߺ��˻�
				string mergeStr;
				mergeStr.assign(notUniqueRelation.at(j).at(i));
				mergeStr.append(notUniqueRelation.at(j).at(k));
				tuple.push_back(mergeStr);
			}
			if (isPrimary(tuple))
				answer++;
		}
	}


	return answer;
}