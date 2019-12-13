#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	int Lidx = 0, Ridx = 0;
	int maxSize = left.size(); // 양쪽 사이즈 같음

	while (1) {
		if ((Lidx == left.size()) || (Ridx == right.size()))
			break;

		if (left[Lidx] > right[Ridx]) {

			answer += right[Ridx];
			Ridx++;
		}
		else {
			Lidx++;
		}
	}



	return answer;
}