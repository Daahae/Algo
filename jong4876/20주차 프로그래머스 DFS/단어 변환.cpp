#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int visited[51]; // none visited : 0 / visited : 1
int answer = 0;

queue<int> Q;

int countSameWords(string begin, string target) {

	int cnt = 0;
	for (int i = 0; i < begin.length();i++) {
			if (target[i] == begin[i])
				cnt++;
	}
	return cnt;

}


void BFS(string begin, string target, vector<string> words) {
	// 단어 하나만 조작해서 나올 수 있는 방향으로 BFS
	int answerFlag = 0;

	while (!Q.empty()) {
		answer++;
		int Qsize = Q.size();

		// 큐 사이즈만큼 순환 **
		for (int k = 0;k < Qsize;k++) {
			int startIdx = Q.front();
			Q.pop();

			//목적지에 다다랐으면 종료
			if (countSameWords(words[startIdx], target) == target.length()) {
				answerFlag = 1;
				return;
			}

			int cnt;
			for (int i = 0;i < words.size();i++) {
				if (visited[i] == 0) { 
					// 방문하지 않은 word에 대해서
					cnt = countSameWords(words[startIdx], words[i]);
					if (cnt >= target.length()-1) {
						visited[i] = 1;
						Q.push(i);
						// 목적string이 있는지 파악
					}
				}
			}
			
		}
	}

	if (answerFlag == 0)
		answer = 0;

}

int solution(string begin, string target, vector<string> words) {
	int startIdx;

	// 한번의 단어 변화로 얻을 수 있는 string의 인덱스를 큐에 삽입
	for (int i = 0;i < words.size();i++) {
		int cnt = countSameWords(begin, words[i]);
		
		// size가 3이 아닐수 있음을 간과함 ****** 검토잘할것
		if (cnt >= target.length()-1) {
			startIdx = i;
			Q.push(startIdx);
			visited[startIdx] = 1;

			if (countSameWords(words[startIdx], target) == target.length())
				return 1;
		}
	}

	BFS(begin, target, words);


	return answer;
}
