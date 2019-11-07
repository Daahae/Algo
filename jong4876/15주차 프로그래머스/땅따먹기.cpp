#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
	int maxRow = land.size();
	

	for (int i = 0;i < maxRow-1;i++) {
		for (int j = 0;j < 4;j++) {
			int maxTmp = -1;
			for (int k = 0;k < 4;k++) {	
				if (k != j)
					maxTmp = max(maxTmp, land[i][k]);
			}
			land[i + 1][j] = land[i+1][j] + maxTmp;
		}
	}
	int maxScore = 0;

	for (int i = 0;i < 4;i++) {
		maxScore = max(maxScore, land[maxRow - 1][i]);
	}
	
	return maxScore;
}
