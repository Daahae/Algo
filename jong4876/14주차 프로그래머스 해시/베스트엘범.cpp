#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(const pair<string, int> a, const pair<string, int> b ) {
	return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> musicMap;

	for (int i = 0;i < genres.size();i++) {
		musicMap[genres[i]] = 0;
	}

	for (int i = 0;i < genres.size();i++) {
		musicMap[genres[i]] += plays[i];
	}

	// map을 벡터로 복사
	std::vector<std::pair<string, int> > vec(musicMap.begin(), musicMap.end());

	// 재생 횟수를 기준으로 내림차순
	sort(vec.begin(), vec.end(), cmp); 

	int cnt = 0;
	int idx = 0;

	// 각 장르당 최대 2개씩 최댓값의 고유번호를 뽑아내고 해당 고유번호 삭제
	while(1){
		if (cnt == 2) {
			cnt = 0;
			idx++;
		}
		if (vec.size() <= idx)
			break;

		string tmp = vec[idx].first; // 재생횟수의 내림차순으로 뽑아내는 장르이름

		int maxPlay = -1;
		int maxPlayIdx;
		int flag = 0;
		for (int j = 0;j < genres.size();j++) {
			if (tmp ==genres[j]&& plays[j] > maxPlay) {
				maxPlay = plays[j];
				maxPlayIdx = j;
				flag = 1;
			}
		}

		// 장르가 2개미만인 경우 거르기
		if (flag == 1) { 
			answer.push_back(maxPlayIdx);
			plays[maxPlayIdx] = -1;
		}
		cnt++;
	}

	return answer;
}