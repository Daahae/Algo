#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<int> citations) {
	int h = 0;
	sort(citations.begin(), citations.end(), greater<int>());


	int overCnt = 0; // h번 이상 인용된 논문 수
	for (int i = 0;i < citations.size();i++) {
		if (citations[i] <= h)
			break;
		
		
		h++;
	}
	return h;

}