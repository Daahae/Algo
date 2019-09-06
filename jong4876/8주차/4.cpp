#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;


int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int size = food_times.size();
	int zeroFlag = 0;

	while (1) {
		zeroFlag = 0;
		for (int i = 0;i < food_times.size();i++) { // -1±ð±â

			if (k == -1) {
				answer = i;
				return answer;
			}

			if (food_times.at(i) != 0) {
				food_times.at(i)--;
				k--;
				zeroFlag = 1;
			}
			else if (food_times.at(i) == 1) {
				size--;
				food_times.at(i)--;
				k--;
				zeroFlag = 1;
			}
		}
		if (zeroFlag == 0)
			return -1;
	}
}