#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int size = food_times.size();
    int index = 0, zero = 0;

    /* 
     * k초 만큼 반복
     * 단, 음식을 다먹었으면(값이 0)
     * 초를 세지않고 다음 음식으로 넘어감
     * 인덱스 0번 부터 음식의 개수까지 반복했을 때
     * 모든 음식을 다먹었으면 종료
     */
    while (k > 0) {
        if (food_times[index] != 0) {
            food_times[index] -= 1;
            k -= 1;
        } else if (food_times[index] == 1){
            food_times[index] -= 1;
            k -= 1;
            zero += 1;
        } else {
            zero += 1;
        }

        index += 1;
        if (index == size) {
            if (zero == size) {
                return -1;
            }
            index = 0;
            zero = 0;
        }
    }

    /*
     * k초의 시간이 지나고
     * 모든 음식을 다먹었는지 검사
     */
    zero = 0;
    for (int i = 0; i < size; i++) {
        if (food_times[i] == 0) {
            zero +=1;
        }
    }

    if (zero == size) {
        return -1;
    } else {
        /* 
         * 방송이 정상화 될때
         * 다음 먹을 음식의 위치 탐색
         */
        while (food_times[index] == 0) {
            index += 1;
            if (index == size) {
                index = 0;
            }
        }
        return index + 1;
    }
}