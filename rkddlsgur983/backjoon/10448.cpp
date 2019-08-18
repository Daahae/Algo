// 10448 유레카 이론
#include <iostream>
#include <cmath>

using namespace std;

// 근의공식 값이 정수 인지 확인
bool isTrianglarSum(int z) {
    if (floor(sqrt(8*z+1)) == ceil(sqrt(8*z+1))) {
        return true;
    } else {
        return false;
    }
}

// 삼각수의 합
int triangularSum(int n) {
    return n*(n+1)/2;
}

// 어떤 수를 넘지않는 최대 삼각수
int maxTriSumSmallerThanNum(int k) {
    return (ceil(sqrt(8*k+1)) - 1) / 2;
}

/*
 * x: 입력 값
 * maxX: x를 넘지않는 최대 삼각수
 * y: x에서 삼각수의 합을 뺀 값
 * maxY: y를 넘지 않는 최대 삼각수
 * z: y에서 삼각수의 합을 뺀 값
 * 
 * 아래 함수에서 1이 반환되는 조건
 * : i, j, z가 모두 삼각수이며 0보다 큰 경우
 */
int func(int x) {
    
    int maxX = maxTriSumSmallerThanNum(x);
    for (int i = maxX; i > 0; i--) {
        int y = x - triangularSum(i);
        int maxY = maxTriSumSmallerThanNum(y);
        for (int j = maxY; j > 0; j--) {
            int z = y - triangularSum(j);
            if (z != 0 && isTrianglarSum(z)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, input;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        cout << func(input) << endl;
    }

    return 0;
}