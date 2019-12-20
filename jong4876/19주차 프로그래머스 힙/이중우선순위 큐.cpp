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
		long val;

		order = operations[i][0];

		for (int j = 2;j < operations[i].length();j++) {
			strVal += operations[i][j];
		}
		val = stol(strVal.c_str());

		if (order == 'I') {
			PQ.push_back(val);
		}
		else if(order == 'D'){
			if (PQ.size() == 0)
				continue;

			if (val == 1)  // 최댓값 삭제
				PQ.pop_back();


			else if(val == -1) // 최솟값 삭제
				PQ.erase(PQ.begin());
		}
		sort(PQ.begin(), PQ.end()); // 삽입이든 삭제든 한 명령 수행후 바로 정렬 ***
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
