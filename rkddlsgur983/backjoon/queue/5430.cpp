// BOJ queue 5430 AC
#include <iostream>
#include <deque>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

deque<int> split(string str, char delimiter) {
    deque<int> dq;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        dq.push_back(atoi(temp.c_str()));
    }
 
    return dq;
}

int main() {
    int t, n;
    string p, input;
    deque<int> dq;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> p;
        cin >> n;        
        cin >> input;
        dq = split(input.substr(1, input.length()-2), ',');

        bool isFront = true;
        bool isError = false;
        for (int j = 0; j < p.length(); j++) {
            switch (p[j]) {
                case 'R':
                    isFront = !isFront;
                    break;
                case 'D':
                    if (dq.empty()) {
                        cout << "error" << endl;
                        j = p.length();
                        isError = true;
                        break;
                    }
                    if (isFront) {
                        dq.pop_front();
                    } else {
                        dq.pop_back();
                    }
                    break;
            }
        }
        if (!isError && isFront) {
            cout << '[';
            while (!dq.empty()) {
                if (dq.size() == 1) {
                    cout << dq.front();
                } else {
                    cout << dq.front() << ',';
                }
                dq.pop_front();
            }
            cout << ']' << endl;
        } else if (!isError && !isFront) {
            cout << '[';
            while (!dq.empty()) {
                if (dq.size() == 1) {
                    cout << dq.back();
                } else {
                    cout << dq.back() << ',';
                }
                dq.pop_back();
            }
            cout << ']' << endl;
        }
    }
    return 0;
}