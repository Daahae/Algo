/* 베스트앨범
 * 2019.10.21
 */
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool compare_g(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool compare_p(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    map<string, int> g; // 장르, 총 재생 횟수
    map<string, vector<pair<int, int>>> p; // 장르, 재생 횟수, 고유 번호
    for (int i = 0; i < genres.size(); i++) {
        if (g.end() == g.find(genres[i])) {
            g.insert(make_pair(genres[i], plays[i]));
            vector<pair<int, int> > v;
            v.push_back(make_pair(plays[i], i));
            p.insert(make_pair(genres[i], v));
        } else {
            g[genres[i]] += plays[i];
            p[genres[i]].push_back(make_pair(plays[i], i));
        }
    }

    vector<pair<string, int> > vg(g.begin(), g.end());
    sort(vg.begin(), vg.end(), compare_g); // 총 재생 횟수 순 내림차순

    vector<int> answer;
    for (int i = 0; i < vg.size(); i++) {
        string t = vg[i].first;
        vector<pair<int, int>> v = p[t];
        sort(v.begin(), v.end(), compare_p);
        int s = v.size();
        if (s > 2) {
            s = 2;
        }
        for (int j = 0; j < s; j++) {
            answer.push_back(v[j].second);
        }
    }
    return answer;
}