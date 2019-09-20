#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <sstream>
#include <queue>

using namespace std;

vector<int> numVec;

int main() {
	int T;
	queue<int> Q;
	string order; // 1 ~ 100000
	long long arrSize;
	char arr[410000];
	char *tok;

	cin >> T;
	for (int z = 0;z < T;z++) { // 4
		int front, rear;
		int reverseFlag = 0;
		int breakFlag = 0;
		cin >> order >> arrSize >> arr;

		int size = order.size();

		tok = strtok(arr, "[,]"); // [,]단위로 나누기
		while (tok != NULL) {
			numVec.push_back(stoi(tok));
			tok = strtok(NULL, "[,]");
		}

		// 큐 처럼 사용하기 위한 인덱스
		front = 0;
		rear = arrSize - 1;


		for (int i = 0;i < size;i++) {
			if (order[i] == 'D') { //삭제 명령
				if (front > rear) { // 에러처리
					cout << "error" << endl;
					breakFlag = 1;
					break;
				}

				if (reverseFlag == 0) // erase는 n의시간이 걸림
					front++;
				else
					rear--;
			}

			else if (order[i] == 'R') { // 진짜 바꾸지는 말고 인덱스만 잘 이용해서?
				if (reverseFlag == 0)
					reverseFlag = 1;
				else
					reverseFlag = 0;
			}
		}
		//예외
		if (breakFlag == 1) {
			numVec.clear();
			continue;
		}

		// 0배열 처리
		if (front > rear) { // 에러처리
			cout << "[]" << endl;
			numVec.clear();
			continue;
		}

		//역출력
		if (reverseFlag == 1) {
			cout << "[" << numVec[rear];
			for (int i = rear - 1;i >= front;i--)
				cout << "," << numVec[i];
			cout << "]" << endl;
			numVec.clear();
			continue;
		}

		//출력
		cout << "[" << numVec[front];
		for (int i = front + 1;i <= rear;i++)
			cout << "," << numVec[i];
		cout << "]" << endl;
		numVec.clear();
	}

	return 0;
}