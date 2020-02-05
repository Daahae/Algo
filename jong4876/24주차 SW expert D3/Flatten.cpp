#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <algorithm>


using namespace std;


int main(){
	for (int T = 1;T <= 10;T++) {
		vector<int> box;
		int dumpCnt;
		stack<int> s;
		cin >> dumpCnt;

		for (int i = 0;i < 100;i++) {
			int height;
			cin >> height;
			box.push_back(height);
		}
		for (int i = 0;i < dumpCnt;i++) { 
			sort(box.begin(), box.end()); // 오름차순
			box[0]++;
			box[99]--;
		}
		sort(box.begin(), box.end());
		cout << "#" << T << " " << box[99] - box[0] << endl;

	}
	


	return 0;
}
