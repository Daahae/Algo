#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	vector<int> answerVal;
	int row;
	int col; // row*col == brown + red
	int sum = brown + red; // sum = (redRow + 2) * (redCol +2) 
	row = sum;
	col = 1;

	//red =2 ; 1*2 -> 3*4 

	for (int redRow = 1; redRow <= red; redRow++) {
		int redCol = red / redRow;
		if (redRow *redCol != red)
			continue;

		if ((redRow + 2) * (redCol + 2) == sum) {
			if (redRow > redCol) { // 큰값먼저
				answer.push_back(redRow + 2);
				answer.push_back(redCol + 2);
			}
			else {
				answer.push_back(redCol + 2);
				answer.push_back(redRow + 2);
			}
			break;
		}

	}
	return answer;
}