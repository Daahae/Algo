#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool answer = true;
vector<vector<int>> tmp;


// 한번 돌린 키 값 반환
vector<vector<int>> rotate(vector<vector<int>> key) {
	int N = key.size();
	vector<vector<int>> tmps;
	tmps.resize(N);

	for (int i = 0;i < N;i++) {
		tmps[i].resize(N);
		for (int j = 0;j < N;j++) {
			tmps[i][j] = key[N-1-j][i];
		}
	}
	return tmps;
}

bool isKeyUnrock(vector<vector<int>> key, vector<vector<int>> lock) {
	for (int i = 0;i < lock.size();i++) {
		for (int j = 0;j < lock.size();j++) {
			if (key[i][j] + lock[i][j] !=1)
				return false;
		}
	}
	return true;
}
bool isEnd(vector<vector<int>> key) {
	for (int i = 0;i < key.size();i++) {
		for (int j = 0;j < key.size();j++) {
			if (key[i][j] == 1)
				return false;
		}		
	}
	return true;
}
void printKey(vector<vector<int>> key) {
	for (int i = 0;i < key.size();i++) {
		for (int j = 0;j < key.size() ;j++) 
			cout << key[i][j] << " ";
		cout << endl;
	}
}

// 동서남북으로 밀기
void move(vector<vector<int>> key, vector<vector<int>> lock) {
	int dirX[4] = { 0,0,-1,1 };
	int dirY[4] = { 1,-1,0,0 };
	
	int N = key.size();

	if (isKeyUnrock(key, lock)) {
		answer = true;
		return;
	}
	
	// 계산 종료
	if (isEnd(key))
		return;

	tmp.clear();
	for (int i = 0;i < N + 1;i++) {
		for (int j = 0;j < N + 1;j++) {
			tmp[i][j] = 0;
		}
	}

	for (int k = 0;k < 4;k++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (i + dirX[k] < 0 || j + dirY[k] < 0)
					continue;
				if (i + dirX[k] >= N || j + dirY[k] >= N)
					continue;
				tmp[i + dirX[k]][j + dirY[k]] = key[i][j];
			}
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			key[i][j] = tmp[i][j];
		}
	}

	move(key, lock);
}

// 모든경우의 수를 돌려보기?
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	tmp.resize(21);
	for (int i = 0;i < 21;i++) {
		tmp[i].resize(21);
	}

	// 회전 최대 3번
	for (int i = 0;i < 4;i++) {
		key = rotate(key);
		move(key, lock);
	}

	return answer;
}