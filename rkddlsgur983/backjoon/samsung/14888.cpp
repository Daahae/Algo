// BOJ 14888 연산자 끼워넣기
// 2019.10.16
#include <iostream>

using namespace std;

int n;
int arr[11];

int max_value = -1000000000;
int min_value = 1000000000;

void solution(int index, int value, int plus, int minus, int multiple, int divide) {
    if (index >= n-1) {
        if (max_value < value) {
            max_value = value;
        }
        if (min_value > value) {
            min_value = value;
        }
        return;
    }
    index += 1;
    if (plus >= 1) {
        solution(index, value+arr[index], plus-1, minus, multiple, divide);
    }
    if (minus >= 1) {
        solution(index, value-arr[index], plus, minus-1, multiple, divide);
    }
    if (multiple >= 1) {
        solution(index, value*arr[index], plus, minus, multiple-1, divide);
    }
    if (divide >= 1) {
        solution(index, value/arr[index], plus, minus, multiple, divide-1);
    }
}

int main() {
    int op[4];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    solution(0, arr[0], op[0], op[1], op[2], op[3]);

    cout << max_value << endl;
    cout << min_value;
    return 0;
}