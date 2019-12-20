#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	vector<int> PQ;

	for (int i = 0;i < operations.size();i++) {
		char order;
		string strVal = "";
		int val;

		order = operations[i][0];

		for (int j = 2;j < operations[i].length();j++) {
			strVal += operations[i][j];
		}
		val = atoi(strVal.c_str());

		if (order == 'I') {
			PQ.push_back(val);
		}
		else if(order == 'D'){
			if (PQ.size() == 0)
				continue;

			sort(PQ.begin(), PQ.end()); //오름차순
			if (val  == 1)  // 최댓값 삭제
				PQ.pop_back();


			else if(val <1) // 최솟값 삭제
				 PQ.erase(PQ.begin());
		}
	
	}

	if (PQ.size() == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(PQ[PQ.size() - 1]); 
		answer.push_back(PQ[0]);
	}


	return answer;
}