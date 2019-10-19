// BOJ 3190 뱀
// 시뮬레이션
// 2019.10.17
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int graph[101][101];

int end_time;

bool isValid(pair<int, int> x) {

    if (x.first < 1 || x.first > n) {
        return false;
    }
    if (x.second < 1 || x.second > n) {
        return false;
    }
    return true;
}

int getDirection(int d, char c) {

    if (c == 'L') {
        if (d == 0) {
            return 2;
        } else if (d == 1) {
            return 3;
        } else if (d == 2) {
            return 1;
        } else if (d == 3) {
            return 0;
        }
    } else if (c == 'D') {
        if (d == 0) {
            return 3;
        } else if (d == 1) {
            return 2;
        } else if (d == 2) {
            return 0;
        } else if (d == 3) {
            return 1;
        }
    }
}

void simulation(int time, int d, deque<pair<int, int> > snake, queue<pair<int, char> > direction) {

    if (!direction.empty()) {
        if (time == direction.front().first) {
            d = getDirection(d, direction.front().second);
            direction.pop();
        }
    }

    // 방향d에 따른 다음 위치를 구함
    int next_x, next_y;
    pair<int, int> next;
    if (d == 0) { // 상
        next_x = snake.front().first-1;
        next_y = snake.front().second;
        next = make_pair(next_x, next_y);
    } else if (d == 1) { // 하
        next_x = snake.front().first+1;
        next_y = snake.front().second;
        next = make_pair(next_x, next_y);
    } else if (d == 2) { // 좌
        next_x = snake.front().first;
        next_y = snake.front().second-1;
        next = make_pair(next_x, next_y);
    } else if (d == 3) { // 우
        next_x = snake.front().first;
        next_y = snake.front().second+1;
        next = make_pair(next_x, next_y);
    }

    /* 다음 이동할 칸이 벽이 아니고 
     * 자신의 몸 (graph[x][y] 값이 2인 경우)과 부딪히면 게임 종료
     */
    if (isValid(next) && graph[next_x][next_y] != 2) {
        if (graph[next_x][next_y] == 1) { // 다음칸에 사과가 있다면
            graph[next_x][next_y] = 2;
            snake.push_front(next); // 머리를 다음칸에 위치시킨다.
            simulation(time+1, d, snake, direction);
        } else { // 사과가 없다면
            graph[next_x][next_y] = 2;
            snake.push_front(next); // 머리를 다음칸에 위치시키고
            graph[snake.back().first][snake.back().second] = 0;
            snake.pop_back(); // 몸길이를 줄여 꼬리가 위치한 칸을 비워준다.
            simulation(time+1, d, snake, direction);
        }
    } else {
        end_time = time+1;
        return;
    }
}

int main() {
    int k;
    cin >> n;
    cin >> k;
    
    int r, c;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        graph[r][c] = 1; // 사과
    }

    int l;
    cin >> l;
    queue<pair<int, char> > direction;
    int x;
    char y;
    for (int i = 0; i < l; i++) {
        cin >> x >> y;
        direction.push(make_pair(x, y));
    }

    deque<pair<int, int> > snake;
    snake.push_back(make_pair(1, 1));
    simulation(0, 3, snake, direction);

    cout << end_time;
    return 0;
}