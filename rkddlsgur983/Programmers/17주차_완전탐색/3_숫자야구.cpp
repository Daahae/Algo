/* 숫자 야구
 * 2019.11.26
 */
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {

    bool arr[988];
    /* 초기화
     * 123 ~ 987 true
     * 중복되는 자리수 or 0인경우 false
     */
    memset(arr, true, sizeof(arr));
    for (int i = 0; i <= 122; i++) {
        arr[i] = false;
    }
    for (int i = 123; i <= 987; i++) {
        string temp = to_string(i);
        if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2]) {
            arr[i] = false;
        }
        if (temp[1] == '0' || temp[2] == '0') {
            arr[i] = false;
        }
    }

    for (auto b: baseball) {
        for (int i = 123; i <= 987; i++) {
            if (arr[i]) {
                int strike = 0, ball = 0;
                string tempa = to_string(b[0]), tempb = to_string(i);
                
                if (tempa[0] == tempb[0]) strike++;
                else if (tempa[0] == tempb[1]) ball++;
                else if (tempa[0] == tempb[2]) ball++;

                if (tempa[1] == tempb[1]) strike++;
                else if (tempa[1] == tempb[0]) ball++;
                else if (tempa[1] == tempb[2]) ball++;

                if (tempa[2] == tempb[2]) strike++;
                else if (tempa[2] == tempb[0]) ball++;
                else if (tempa[2] == tempb[1]) ball++;

                if (strike != b[1] || ball != b[2]) {
                    arr[i] = false;
                } 
            }
        }
    }

    int answer = 0;
    for (int i = 123; i <= 987; i++) {
        if (arr[i]) {
            answer++;
        }
    }
    return answer;
}