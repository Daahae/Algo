/* 큰 수 만들기
 * 2019.11.11
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {

    int r = 0; // 제거한 문자 길이
    int len = number.length();
    string answer;
    while (answer.length() < len-k) {
        int max_value = 0;
        int index = 0;
        for (int i = 0; i <= k-r; i++) {
            if (max_value < number[i]-'0') {
                max_value = number[i]-'0';
                index = i;
            }
        }
        r += index;
        answer += number[index];
        number = number.substr(index+1, number.length()-1-index);
    }
    return answer;
}

int main() {
    cout << solution("1924", 2) << "\n"; // 94
    cout << solution("1231234", 3) << "\n"; // 3234
    cout << solution("4177252841", 4) << "\n"; // 775841
    cout << solution("2791", 2); // 91
    return 0;
}