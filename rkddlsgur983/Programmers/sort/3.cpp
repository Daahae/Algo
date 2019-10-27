// sort H-Index
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end(), greater<int>());

    int hindex = 0;
    for (int h = citations[0]; h >= 0; h--) {
        int index = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= h) {
                index = i;
            } else {
                break;
            }
        }
        if (index+1 >= h && citations.size()-index-1 <= h) {
            hindex = h;
            break;
        }
    }

    int answer = hindex;
    return answer;
}