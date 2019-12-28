#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {

	int answer = 0;
	int boat = 0;
	int j;
	int rightIdx = people.size() - 1; // 끝 인덱스를 줄여나감

	sort(people.begin(), people.end());

	//50 50 70 80
	for (int i = 0;i < people.size();i++) {
		if (people[i] == -1)
			continue;

		boat += people[i];

		// 다른 사람을 태울수 있는지 확인
		if (boat + people[i + 1] <= limit) {

			// 태울수 있다면 가능한 최댓값의 사람부터 태움
			for (j = rightIdx;j >= i + 1;j--) {

				if (people[j] != -1 && (boat + people[j] <= limit)) {
					boat += people[j];
					people[j] = -1;
					rightIdx = j-1; // 종료된 위치로 인덱스 한정 **** -> 이 이상으로 큰값을 탐색하는 건 의미없음
					break;
				}
			}
		}


		answer++;
		boat = 0;
		people[i] = -1;
	}


	return answer;
}
