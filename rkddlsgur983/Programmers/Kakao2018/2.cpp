// 2018 KAKAO BLIND RECURITMENT 2. 실패율
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(pair<int, float> a, pair<int, float> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

vector<int> solution(int N, vector<int> stages) {

    sort(stages.begin(), stages.end());

    int size = stages.size(), index = 0;
    vector<pair<int, float>> arr;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (; index < stages.size();) {
            if (stages[index] == i) {
                cnt += 1;
                index += 1;
            } else {
                break;
            }
        }
        if (size == 0 && cnt == 0) {
            arr.push_back(pair<int, float>(i, 0));
        } else if (size - cnt == 0 && cnt > 0) {
            arr.push_back(pair<int, float>(i, 1));
        }else {
            arr.push_back(pair<int, float>(i, (float)cnt / (float)size));
        }
        size -= cnt;
    }

    sort(arr.begin(), arr.end(), compare);
    
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++) {
        answer.push_back(arr[i].first);
    }
    return answer;
}