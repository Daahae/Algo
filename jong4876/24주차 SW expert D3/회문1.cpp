#include<iostream>

using namespace std;

bool isPalin(string str) {
	
	for (int i = 0;i < str.length()/2;i++) {
		if (str[i] != str[str.length() - 1 -i]) {
			return false;
		}
	}
	return true;
}


int dfs(char adj[9][9], int length, int x, int y) {
	// 한 인덱스에서 동남으로 회문조사
	string str;
	int answer = 0;

	//출발하는 수 빼야되서?
	length--; 

	// 남쪽
	if (x + length <= 8) {
		str = "";
		for (int i = x;i <= x + length;i++) {
			str += adj[i][y];
		}
		if (isPalin(str)) 
			answer++;
	}

	// 동쪽
	if (y + length <= 8) {
		str = "";
		for (int i = y;i <= y + length;i++) 
			str += adj[x][i];
		
		if (isPalin(str)) 
			answer++;
	}
	return answer;
}



int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		char adj[9][9];
		int length; // 구해야 하는 회문의 길이

		cin >> length;
		
		//1,1에서 시작 8,8까지 있음
		for (int i = 1;i <= 8;i++) {
			for (int j = 1;j <= 8;j++) {
				char tmp;
				cin >> tmp;
				adj[i][j] = tmp;
			}
		}

		int answer = 0;

		if (length == 1) {
			answer = 64;
		}
		else {
			// 모든 인덱스에 대하여 동, 남쪽으로 회문검사
			for (int i = 1;i <= 8;i++) {
				for (int j = 1;j <= 8;j++) {
					answer += dfs(adj, length, i, j);
				}
			}
		}

		cout << "#" << test_case << " " << answer<<endl;
	}
	return 0;
}