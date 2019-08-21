// 2503 숫자 야구
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
bool arr[988];
vector<pair<int, pair<int, int> > > pitches;

bool desc(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2) {
    
    if (p1.second.first == p2.second.first) {
        return p1.second.second > p2.second.second;
    } else {
        return p1.second.first > p2.second.first;
    }
}

void init() {

    for (int i = 123; i <= 987; i++) {
        string num = to_string(i);
        if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) {
            arr[i] = false;
        } else if (num[0] == '0' || num[1] == '0' || num[2] == '0') {
            arr[i] = false;
        } else {
            arr[i] = true;
        }
    }
}

void searchPitch() {

    for (int i = 0; i < n; i++) {
        for (int j = 123; j <= 987; j++) {
            if (arr[j]) {
                int strikeCnt = 0, ballCnt = 0;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        string pitch = to_string(pitches[i].first);
                        string num = to_string(j);
                        if (pitch[x] == num[y] && x == y) {
                            strikeCnt += 1;
                        } else if (pitch[x] == num[y] && x != y) {
                            ballCnt += 1;
                        }
                    }
                }
                if (strikeCnt != pitches[i].second.first
                || ballCnt != pitches[i].second.second) {
                    arr[j] = false;
                }
            }
        }
    }
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num, strike, ball;
        cin >> num >> strike >> ball;
        pitches.push_back(pair<int, pair<int, int> >(num, pair<int, int>(strike, ball)));
    }

    sort(pitches.begin(), pitches.end(), desc);

    if (pitches[0].second.first == 3) {
        cout << 1 << endl;
    } else {
        /*
         * search pitch
         */
        init();
        searchPitch();
    }

    int result = 0;
    for (int i = 123; i <= 987; i++) {
        if (arr[i]) {
            result += 1;
        }
    }
    cout << result << endl;

    return 0;
}