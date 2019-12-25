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


void BFS(int startIdx, string begin, string target, vector<string> words) {
	// 단어 하나만 조작해서 나올 수 있는 방향으로 BFS
	int answerFlag = 0;

	while (!Q.empty()) {
		answer++;
		int Qsize = Q.size();

		// 큐 사이즈만큼 순환 **
		for (int k = 0;k < Qsize;k++) {
			startIdx = Q.front();
			Q.pop();

			//목적지에 다다랐으면 종료
			if (target.compare(words[startIdx]) == 0) {
				answerFlag = 1;
				return;
			}

			int cnt;
			for (int i = 0;i < words.size();i++) {
				if (visited[i] == 0) { 
					// 방문하지 않은 word에 대해서
					cnt = countSameWords(words[startIdx], words[i]);
					if (cnt == 2) {
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

	// 한번의 단어 변화로 얻을 수 있는 string을 startIdx로
	for (int i = 0;i < words.size();i++) {
		int cnt = countSameWords(begin, words[i]);
		if (cnt == 2) {
			Q.push(startIdx);
			visited[startIdx] = 1;

			cnt = countSameWords(target, words[i]);
			if (cnt == 3)
				return 1;
		}
	}

	BFS(startIdx, begin, target, words);


	return answer;
}