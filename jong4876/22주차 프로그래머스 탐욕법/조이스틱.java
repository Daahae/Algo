class Solution {
	public int solution(String name) {
		int answer = 0;
		int answerRight = 0;
		int answerLeft = 0;
		int flag = 0;
		
		// 모든경우 탐색 후 최솟값 리턴 *

		// 정방향 출발
		int sum = 0;// 누적합
		for (int i = 0; i < name.length(); i++) {
			if (name.charAt(i) == 'A') {
				sum++;
				continue;
			}

			int upCharGap = (int) name.charAt(i) - (int) 'A';
			int downCharGap = 26 - upCharGap;
			downCharGap = Math.abs(downCharGap);

			answerRight += Math.min(upCharGap, downCharGap);
			answerRight += sum;
			sum = 1;
		}

		// 역방향으로 출발
		sum = 0;
		for (int i = name.length(); i > 0; i--) {
			if (name.charAt(i % name.length()) == 'A') {
				sum++;
				continue;
			}

			int upCharGap = (int) name.charAt(i % name.length()) - (int) 'A';
			int downCharGap = 26 - upCharGap;
			downCharGap = Math.abs(downCharGap);

			answerLeft += Math.min(upCharGap, downCharGap);
			answerLeft += sum;
			sum = 1;
		}

		// 역+1 방향으로 출발 -> 앞으로갔다가 역으로 돌아가는 경우
		sum = 1;
		int answerMid = 0;
		for (int i = name.length() + 1; i > 1; i--) {
			if (name.charAt(i % name.length()) == 'A') {
				sum++;
				continue;
			}

			int upCharGap = (int) name.charAt(i % name.length()) - (int) 'A';
			int downCharGap = 26 - upCharGap;
			downCharGap = Math.abs(downCharGap);

			answerMid += Math.min(upCharGap, downCharGap);
			answerMid += sum;
			sum = 1;
		}
		
		// 3값중에 최솟값 리턴
		answer = Math.min(answerRight, answerLeft);
		answer = Math.min(answer, answerMid);

		return answer;
	}
}
