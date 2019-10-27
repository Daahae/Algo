/* 전화번호 목록
 * 2019.10.20
 */
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool shorter(string a, string b) {
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end(), shorter);

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = i+1; j < phone_book.size(); j++) {
            if (phone_book[i].compare(phone_book[j].substr(0, phone_book[i].length())) == 0) {
                return false;
            }
        }
    }
    return true;
}