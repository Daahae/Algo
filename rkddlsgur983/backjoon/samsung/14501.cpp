// BOJ 14501 퇴사
// 브루트 포스
// 2019.10.18
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int> > consult;
int max_pay = 0;

void DFS(int index, int time, int pay) {

    if (index >= n) {
        max_pay = max(max_pay, pay);
        return;
    }

     // 상담 안하는 경우
    if (time == 0) {
        DFS(index+1, time, pay);
    } else {
        DFS(index+1, time-1, pay);
    }

     // 상담 하는 경우
    if (index + consult[index].first <= n) {
        if (time == 0) {
            time = consult[index].first;
            pay += consult[index].second;
        }
        DFS(index+1, time-1, pay);
    } else { // 상담 못하는 경우
        if (time == 0) {
            DFS(index+1, time, pay);
        } else {
            DFS(index+1, time-1, pay);
        }
    }
}

int main(){

    cin >> n;
    int t, p;
    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        consult.push_back(make_pair(t, p));
    } 

    DFS(0, 0, 0);

    cout << max_pay;
    return 0;
}