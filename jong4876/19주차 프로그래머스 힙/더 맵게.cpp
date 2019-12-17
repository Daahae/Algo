#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int firstIdx = 0;

	sort(scoville.begin(), scoville.end());
	while (scoville[firstIdx] < K ) {
		if (firstIdx >= scoville.size()) {
			answer = -1;
			break;
		}

		scoville[firstIdx+1] = scoville[firstIdx] + scoville[firstIdx+1]*2;
		sort(scoville.begin() + firstIdx + 1, scoville.end());
		firstIdx++;
	}


	return answer;
}