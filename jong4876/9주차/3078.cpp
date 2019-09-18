#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <sstream>
#include <queue>

using namespace std;

int main(){
	queue<int> Q;
	queue<int> tmpQ;
	vector<int> nameLengthVec;
	int N, K;
	long long cnt = 0;
	int flag = 0;
	int beforeLen = -1;

	cin >> N >> K; 

	for (int i = 0;i < N;i++) {
		string tmp;
		cin >> tmp;
		nameLengthVec.push_back(tmp.length());
	}
	
	for (int i = 0;i < N;i++) {
		Q.push(nameLengthVec[i]);

		if (Q.front() == nameLengthVec[i] && Q.size() !=1) {
			cnt++;
			Q.pop();
		}
		else if (Q.size() > K) { //큐가 꽉차면
			Q.pop(); //큐의 맨앞 삭제후 다음 원소부터 계속하여 비교
			if (Q.front() == nameLengthVec[i] && Q.size() != 1) {
				cnt++;
			}
		}

		if (beforeLen == nameLengthVec[i]) { // 하나차이 구별을 위함
			i++;
			cnt++;
		}
		if (i >= N)
			break;
		beforeLen = nameLengthVec[i];
	}
	cout << cnt;
	
	
	return 0;
}