import java.util.Arrays;
import java.util.Comparator;

class Solution {
	public int solution(int[][] routes) {
		int answer = 0;

		// 첫 번째 행렬 기준으로 정렬
		Arrays.sort(routes, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return o1[0] - o2[0];
			}
		});
		int left = routes[0][0];
		int right = routes[0][1];

		for (int i = 1; i < routes.length; i++) {

			// 범위 좁혀나가기
			if (left <= routes[i][0] && right >= routes[i][1]) {
				left = routes[i][0];
				right = routes[i][1];
			}

			else if (left <= routes[i][1] && routes[i][1] <= right)
				right = routes[i][1];

			else if (right >= routes[i][0] && routes[i][0] >= left)
				left = routes[i][0];

			// 범위를 못 좁힌다면 갱신 후 카운트
			else {
				answer++;
				left = routes[i][0];
				right = routes[i][1];
			}
		}
		return answer + 1;
	}
}
