#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	
	if (a.second == b.second)
		return a.first < b.first;

	else
		return a.second < b.second;
}


int calculateAvg(vector<pair<int, int>> pairJobs) {
	queue<pair<int, int>> Q;
	int resSum = 0;
	int presentIdx = 0;
	int jobsSize = pairJobs.size();

	for (int i = 0;i < pairJobs.size();i++)
		Q.push(pairJobs[i]);

	while (!Q.empty()) { // resSum  3 ,  before  3
		resSum += Q.front().second;

		if(Q.front().first >= presentIdx)
			presentIdx = Q.front().first + Q.front().second;

		else {
			int diff = presentIdx - Q.front().first;
			resSum += diff;
			presentIdx = Q.front().first + Q.front().second+ diff;
		}

		Q.pop();
	}

	


	return resSum / jobsSize;

}



int solution(vector<vector<int>> jobs) {
	int answer = 0;
	vector<pair<int, int>> pairJobs;


	for (int i = 0;i < jobs.size();i++) {
		pairJobs.push_back(pair<int, int>(jobs[i][0], jobs[i][1]));
	}


	sort(pairJobs.begin(), pairJobs.end(), compare);

	answer = calculateAvg(pairJobs);


	return answer;
}