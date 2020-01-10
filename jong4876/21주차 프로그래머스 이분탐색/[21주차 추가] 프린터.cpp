#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;



int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<pair<int, int>> Q; // location, priorities
	
	for (int i = 0;i < priorities.size();i++) {
		Q.push_back(pair<int, int>(i, priorities[i]));
	}

	while (1) {
		pair<int, int> frontPair = Q[0];
		int front = frontPair.second;
		int flag = 0;

		for (int i = 1;i < Q.size();i++) {
			if (front < Q[i].second) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			break;
		
		
		Q.erase(Q.begin());
		Q.push_back(frontPair);
	}


	for (int i = 0;i < Q.size();i++) {
		if (Q[i].first == location)
			return Q[i].second;
	}

	
	return answer;
}