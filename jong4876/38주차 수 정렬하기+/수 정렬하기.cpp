#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> vec;
	
	cin >> N;

	vec.resize(10001);
	fill(vec.begin(), vec.end(), 0);

	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		vec[num]++;	
	}


	for (int i = 1;i <=10000;i++) {	
		for (int j = 0;j < vec[i];j++) 
			cout << i <<"\n";
	}

	return 0;
}