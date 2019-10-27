// sort 가장 큰 수
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool greater_sum(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {

    vector<string> s;
    for (int i = 0; i < numbers.size(); i++) {
        s.push_back(to_string(numbers[i]));
    }
    sort(s.begin(), s.end(), greater_sum);

    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        answer += s[i];
    }
    if (answer[0] == '0') {
        return "0";
    }
    return answer;
}