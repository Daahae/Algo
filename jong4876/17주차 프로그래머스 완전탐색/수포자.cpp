#include <string>
#include <vector>
#include<algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> answerCntByPlayer;
	vector<int> player1 = {1,2,3,4,5};
	vector<int> player2 = {2,1,2,3,2,4,2,5};
	vector<int> player3 = {3,3,1,1,2,2,4,4,5,5};
	int answerCnt1 = 0;
	int answerCnt2 = 0;
	int answerCnt3 = 0;
	//12345
	//21232425
	//3311224455
	
	for (int i = 0;i < answers.size();i++) {
	
		int idx = (i % player1.size());

	
		if (answers[i] == player1[idx]) {
			answerCnt1++;
		}
	
		idx = (i % player2.size());
		if (answers[i] == player2[idx]) {
			answerCnt2++;
		}

		
		idx = (i % player3.size());
		if (answers[i] == player3[idx]) {
			answerCnt3++;
		}
	}
	answerCntByPlayer.push_back(answerCnt1);
	answerCntByPlayer.push_back(answerCnt2);
	answerCntByPlayer.push_back(answerCnt3);



	int max = -1;
	for (int i = 0;i < 3;i++) {
		cout << answerCntByPlayer[i];
		if (max < answerCntByPlayer[i])
			max = answerCntByPlayer[i];

	}
	for (int i = 0;i < 3;i++) {
		if (max == answerCntByPlayer[i])
			answer.push_back(i + 1);
	}


	return answer;
}