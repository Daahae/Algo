#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(const int &a, const int &b) {
	
	return a>b;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	// 최댓값 부터 시작하여 1자리 스왑을 통해 가능 한것인지? 판단
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int val;
		int dupleFlag = 0;
		double swapCnt;
		vector<int> valVec;
		vector<int> tmpValVec;

		cin >> val >> swapCnt;

		//vector로 관리
		while (val > 0) {
			valVec.push_back(val % 10);
			val /= 10;
		}

		for (int i = valVec.size() - 1;i >= 0;i--)
			tmpValVec.push_back(valVec[i]);

		//내림차순 정렬
		sort(valVec.begin(), valVec.end(), compare);
		
		do {
			double changeCnt = 0.0;
			for (int i = 0;i < valVec.size();i++) {
				if (valVec[i] != tmpValVec[i])
					changeCnt++;
			}

			if (swapCnt*2 == changeCnt) {
				cout << "#" << test_case << " ";

				for (int i = 0;i < valVec.size();i++)
					cout << valVec[i];
				cout << endl;
				break;
			}
		} while (prev_permutation(valVec.begin(), valVec.end()));
		
	}
	return 0;
}