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

		tok = strtok(arr, "[,]"); // [,]������ ������
		while (tok != NULL) {
			numVec.push_back(stoi(tok));
			tok = strtok(NULL, "[,]");
		}

		// ť ó�� ����ϱ� ���� �ε���
		front = 0;
		rear = arrSize - 1;


		for (int i = 0;i < size;i++) {
			if (order[i] == 'D') { //���� ���
				if (front > rear) { // ����ó��
					cout << "error" << endl;
					breakFlag = 1;
					break;
				}

				if (reverseFlag == 0) // erase�� n�ǽð��� �ɸ�
					front++;
				else
					rear--;
			}

			else if (order[i] == 'R') { // ��¥ �ٲ����� ���� �ε����� �� �̿��ؼ�?
				if (reverseFlag == 0)
					reverseFlag = 1;
				else
					reverseFlag = 0;
			}
		}
		//����
		if (breakFlag == 1) {
			numVec.clear();
			continue;
		}

		// 0�迭 ó��
		if (front > rear) { // ����ó��
			cout << "[]" << endl;
			numVec.clear();
			continue;
		}

		//�����
		if (reverseFlag == 1) {
			cout << "[" << numVec[rear];
			for (int i = rear - 1;i >= front;i--)
				cout << "," << numVec[i];
			cout << "]" << endl;
			numVec.clear();
			continue;
		}

		//���
		cout << "[" << numVec[front];
		for (int i = front + 1;i <= rear;i++)
			cout << "," << numVec[i];
		cout << "]" << endl;
		numVec.clear();
	}

	return 0;
}