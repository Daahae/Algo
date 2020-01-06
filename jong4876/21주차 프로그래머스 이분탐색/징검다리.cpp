#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	vector<int> diffVec;
	//dest = 25

	diffVec.push_back(rocks[0]);
	for (int i = 0;i < rocks.size()-1;i++) {
		diffVec.push_back(abs(rocks[i + 1] - rocks[i]));
	}
	diffVec.push_back(distance - rocks[rocks.size() - 1]);
	
	sort(diffVec.begin(), diffVec.end());

	for (int i = 0;i < diffVec.size();i++)
		cout << diffVec[i] << " ";

	answer = diffVec[n - 1];

	return answer;
}