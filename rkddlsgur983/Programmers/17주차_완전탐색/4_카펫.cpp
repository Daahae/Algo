/* 카펫
 * 2019.11.26
 */
#include <math.h>
#include <vector>

using namespace std;

bool dividable(double a, double b) {
    return floor(a/b) == ceil(a/b);
}

vector<int> solution(int brown, int red) {
    
    int sum = brown + red;
    vector<int> answer;

    int height = 3;
    /* O(n2)처럼 보이지만
     * height = (3 ~ sum/height) 범위 내에서 동작함
     */
    while (sum / height >= height) {
        while (!dividable(sum, height)) {
            height++;
        }
        int width = sum / height;
        if (brown == width*2 + (height-2)*2) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
        height++;
    }
    return answer;
}