/* 큰 수 만들기
 * 41.7 / 100
 * 2019.11.11
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {

    int r = 0;
    string answer;
    while (1 < k-r) {
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
    
    for (int i = 0; i < number.length()-1; i++) {
        if (number[i]-'0' < number[i+1]-'0') {
            answer += number.substr(i+1, number.length()-1-i);
            break;
        }
        answer += number[i];
    }
    if (number.length() == 1) {
        answer += number;
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