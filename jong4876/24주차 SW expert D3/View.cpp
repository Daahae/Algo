
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getJomang(vector<int> building, int idx) { 
	// 해당 인덱스에서 몇층까지 조망권 확보되는지 리턴

	int presentHeight = building[idx];
	int jomang = 0;

	//왼쪽 오른쪽 인덱스들 중 최대 값과 현재 인덱스를 비교 후 조망값리턴
	int maxLeft = max(building[idx - 2], building[idx - 1]);
	int maxRight = max(building[idx + 1], building[idx + 2]);
	int maxLeftRight = max(maxLeft, maxRight);

	if (presentHeight >maxLeftRight) {
		return presentHeight - maxLeftRight;
	}


	return 0;
}

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int T;
		int answer = 0;
		vector<int> building;
		cin >> T;//100
		for (int i = 0;i < T;i++) {
			int height;
			cin >> height;
			building.push_back(height);
		}

		for (int i = 2;i < T-2;i++) {
			answer += getJomang(building, i);
		}
		cout << "#" << test_case << " " << answer << endl;

	}
	return 0;
}