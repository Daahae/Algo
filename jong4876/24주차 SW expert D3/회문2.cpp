
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool isLevel(string str) {

	for (int i = 0;i < str.length()/2;i++) {
		if (str[i] != str[str.length() - 1-i])
			return false;
	}
	return true;
}

int getEastLevelLen(char adj[101][101], int x, int y) {
	int answerEast = 1;
	

	//x,y 좌표 기준 동, 남쪽만 회문검사

	string tmp = "";

	// 동쪽
	for (int i = y;i <= 100;i++) {
		tmp += adj[x][i];
		if (isLevel(tmp))
			answerEast = tmp.length();
	}
	return answerEast;
}

int getSouthLevelLen(char adj[101][101], int x, int y) {
	int answerSouth = 1;

	//x,y 좌표 기준 동, 남쪽만 회문검사

	// 남쪽
	string tmp = "";
	for (int i = x;i <= 100;i++) {
		tmp += adj[i][y];
		if (isLevel(tmp))
			answerSouth = tmp.length();
	}
	return answerSouth;
}


int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num;
		int answer = 0;
		char adj[101][101];
		string tmp = "";

		cin >> num;
		cin >> tmp;

		int idx = 0;
		
		for (int i = 1;i <= 100;i++) {
			for (int j = 1;j <= 100;j++) {
				adj[i][j] = tmp[idx];
				idx++;
			}
		}

		int maxLen = 1;
		for (int i = 1;i <= 100;i++) {
			for (int j = 1;j <= 100;j++) {
				int eastLen = getEastLevelLen(adj, i, j);
				int southLen =getSouthLevelLen(adj, i, j);
				int len = max(eastLen, southLen);

				if (eastLen > 1)
					j += (eastLen - 1);
				
				maxLen = max(len, maxLen);

			}
		}
		cout << "#" << test_case << " " << maxLen << endl;

	}
	return 0;
}