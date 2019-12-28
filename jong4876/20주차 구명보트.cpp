#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {

	int answer = 0;
	int boat = 0;
	int j;

	sort(people.begin(), people.end());

	//50 50 70 80

	for (int i = 0;i < people.size();i++) {
		if (people[i] == -1)
			continue;
		
		boat += people[i];
		int flag = 0;

		if (boat + people[i + 1] <= limit) {
			for (j = people.size() - 1;j >= i + 1;j--) {
				if (people[j] != -1 && (boat + people[j] <= limit)) {
					boat += people[j];
					people[j] = -1;
					flag = 1;
				}
			}
		}
		
		answer++;
		boat = 0;
		people[i] = -1;	
	}


	return answer;
}