#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer; //6은 클리어한것
	map<int, double, greater<double>> failRatioMap; // 각 스테이지의 <번호,실패율>, 실패율 순으로 저장
	double notClearPlayer;
	double approachPlayer;
	int stage;

	for (int i = 1;i <= N;i++) {
		stage = i;
		notClearPlayer = 0.0;
		approachPlayer = 0.0;
		for (int j = 0;j < stages.size();j++) {
			if (stages.at(j) >= stage)
				approachPlayer+=1.0;

			if (stages.at(j) == stage)
				notClearPlayer+=1.0;
		}
		if (approachPlayer == 0)
			failRatioMap[stage] = 0.0;

		else
			failRatioMap[stage] = (double)(notClearPlayer / approachPlayer);
	}

	for (int i = 1;i <= failRatioMap.size();i++) {
		double max = -1.0;
		int idx;
		for (int j = 1;j <= failRatioMap.size();j++) {
			if (failRatioMap.at(j) > max) {
				idx = j;
				max = failRatioMap.at(j);
			}
		}
		failRatioMap[idx] = -1.0;
		answer.push_back(idx);
	}


	return answer;
}