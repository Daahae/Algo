// 3085 사탕게임
#include <iostream>

using namespace std;

int n;
char arr[50][50];

int getRowMax(int row) {
    int max = 1, cnt = 1;

    for (int j = 0; j < n-1; j++) {
        if (arr[row][j] == arr[row][j+1]) {
            cnt += 1;
        } else {
            if (max < cnt) {
                max = cnt;
            }
            cnt = 1;
        }
    }
    if (max < cnt) {
        return cnt;
    } else {
        return max;
    }
}

int getColMax(int col) {
    int max = 1, cnt = 1;

    for (int i = 0; i < n-1; i++) {
        if (arr[i][col] == arr[i+1][col]) {
            cnt += 1;
        } else {
            if (max < cnt) {
                max = cnt;
            }
            cnt = 1;
        }
    }
    if (max < cnt) {
        return cnt;
    } else {
        return max;
    }
}

int rowCheck() {
    int max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            /*
             * swap index
             */
            int temp = arr[i][j];
            arr[i][j] = arr[i][j+1];
            arr[i][j+1] = temp;

            int rm = getRowMax(i);
            if (max < rm) {
                max = rm;
            }

            int cm1 = getColMax(j);
            if (max < cm1) {
                max = cm1;
            }

            int cm2 = getColMax(j+1);
            if (max < cm2) {
                max = cm2;
            }

            /*
             * reswap index
             */
            temp = arr[i][j];
            arr[i][j] = arr[i][j+1];
            arr[i][j+1] = temp;
        }
    }

    return max;
}

int colCheck() {
    int max = 0;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n-1; i++) {
            /*
             * swap index
             */
            int temp = arr[i][j];
            arr[i][j] = arr[i+1][j];
            arr[i+1][j] = temp;

            int rm1 = getRowMax(i);
            if (max < rm1) {
                max = rm1;
            }

            int rm2 = getRowMax(i+1);
            if (max < rm2) {
                max = rm2;
            }

            int cm = getColMax(j);
            if (max < cm) {
                max = cm;
            }

            /*
             * reswap index
             */
            temp = arr[i][j];
            arr[i][j] = arr[i+1][j];
            arr[i+1][j] = temp;
        }
    }

    return max;
}

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int rowMax = rowCheck();
    int colMax = colCheck();

    if (rowMax < colMax) {
        cout << colMax << endl;
    } else {
        cout << rowMax << endl;
    }

    return 0;
}