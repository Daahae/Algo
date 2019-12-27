#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> block;

int getMaxHeightIdx(int startIdx, int endIdx) {

	int maxVal = 0;
	int maxIdx = startIdx;
	for (int i = startIdx; i < endIdx;i++) {
		if (maxVal < block[i]) {
			maxVal = block[i];
			maxIdx = i;

		}
	}
	return maxIdx;
	
}

int main() {

	int H, W;
	int answer = 0;

	cin >> H >> W;


	for (int i = 0;i < W;i++) {
		int height;
		cin >> height;
		block.push_back(height);
	}

	int leftIdx = 0;
	int rightIdx;
	int i = 0;

	// 해당 인덱스에 담길수 있는 물의 높이를 더해나감

	for(int i =0;i<W;i++){ 
		int leftIdx = getMaxHeightIdx(0, i+1); // 미만을 인덱스로 지정했기때문 0~i
		int rightIdx = getMaxHeightIdx(i, W); // i ~ W-1
		
		int axis = min(block[leftIdx], block[rightIdx]);
		answer += axis - block[i];
	}


	cout << answer;

	return 0;
}