/* 소수 찾기
 * 2019.11.22
 */
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> num;
vector<int> prime;
bool isVisited[8];

bool isPrime(int n) {

    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i < n; i+=2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void DFS(string number, int size) {

    if (number.length() == size) {
        int num = atoi(number.c_str());
        if (isPrime(num)) {
            prime.push_back(num);
        }
        return;
    }

    for (int j = 0; j < num.size(); j++) {
        if (!isVisited[j]) {
            isVisited[j] = true;
            DFS(number + to_string(num[j]), size);
            isVisited[j] = false;
        }
    }
}

int solution(string numbers) {

    for (int i = 0; i < numbers.length(); i++) {
        num.push_back(numbers[i] - '0');
    }

    for (int i = 1; i <= num.size(); i++) {
        for (int j = 0; j < num.size(); j++) {
            isVisited[j] = true;
            DFS(to_string(num[j]), i);
            isVisited[j] = false;
        }
    }

    sort(prime.begin(), prime.end());
    prime.erase(unique(prime.begin(), prime.end()), prime.end());

    int answer = prime.size();
    return answer;
}