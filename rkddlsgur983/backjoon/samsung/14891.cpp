// BOJ 14891 톱니바퀴
// 시뮬레이션
// 2019.10.19
#include <iostream>
#include <math.h>
#include <string>
#include <queue>

using namespace std;

deque<int> gear[5];
bool isVisited[5] = {false};

bool isValid(int g) {
    return g >= 1 && g <= 4;
}

void DFS(int g, int d) {
    
    int before_left = gear[g][6];
    int before_right = gear[g][2];

    if (d == 1) {
        int p = gear[g].back();
        gear[g].pop_back();
        gear[g].push_front(p);
    } else if (d == -1) {
        int p = gear[g].front();
        gear[g].pop_front();
        gear[g].push_back(p);
    }

    // 왼쪽
    if (isValid(g-1) && !isVisited[g-1] && before_left != gear[g-1][2]) {
        isVisited[g-1] = true;
        if (d == 1) {
            DFS(g-1, -1);
        } else if (d == -1) {
            DFS(g-1, 1);
        }
        isVisited[g-1] = false;
    }
    // 오른쪽
    if (isValid(g+1) && !isVisited[g+1] && before_right != gear[g+1][6]) {        
        isVisited[g+1] = true;
        if (d == 1) {
            DFS(g+1, -1);
        } else if (d == -1) {
            DFS(g+1, 1);
        }
        isVisited[g+1] = false;
    }
}

int main() {

    string input;
    for (int i = 1; i <= 4; i++) {
        cin >> input;
        for (int j = 0; j < input.length(); j++) {
            gear[i].push_back(atoi(input.substr(j,1).c_str()));
        }
    }

    int k;
    cin >> k;
    int g, d;
    for (int i = 0; i < k; i++) {
        cin >> g >> d;
        isVisited[g] = true;
        DFS(g, d);
        isVisited[g] = false;
    }

    int sum = 0;
    for (int i = 1; i <= 4; i++) {
        sum += gear[i].front() * pow(2,i-1);
    }
    cout << sum;
    return 0;
}