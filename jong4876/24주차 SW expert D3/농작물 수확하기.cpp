#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int answer = 0;
		int adj[50][50];

		cin >> N;

		// 예시가 친절하지 않음을 고려
		for (int i = 1;i <= N;i++) {
			string str;
			cin >> str;
			for (int j = 1;j <= N;j++) {
				adj[i][j] = str[j-1]-'0';
			}
		}

		// 기준 열
		int startCol = N / 2 + 1;

		// 기준 열 좌우로 날개로 얼마나 붙일지
		int wing = 0; 
		int reverseFlag = 0;

		
		for (int i = 1;i <= N;i++) {
			answer += adj[i][startCol];

			for (int j = startCol + 1;j <= startCol + wing;j++)
				answer += adj[i][j];

			for (int j = startCol - 1;j >= startCol - wing;j--)
				answer += adj[i][j];

			// 다 차면 날개 줄이기
			if (2*wing+1 == N)
				reverseFlag = 1;

			if (reverseFlag == 0)
				wing++;

			else
				wing--;

		}
		cout << "#" << test_case << " " << answer<<endl;
	}
	return 0;
}