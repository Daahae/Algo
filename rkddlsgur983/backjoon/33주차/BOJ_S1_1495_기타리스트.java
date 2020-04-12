import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * @{link}	https://www.acmicpc.net/problem/1495
 * @date   	2020-04-11
 * @author 	lolol0705
 * @memory 	13916KB / 128MB
 * @time   	88ms / 2초
 * @idea	BFS 방문체크 위치 주의
 */
public class BOJ_S1_1495_기타리스트 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		st = new StringTokenizer(br.readLine(), " ");
		br.close();
		for (int i = 0; i < n; ++i) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Queue<Integer> queue = new LinkedList<>();
		boolean[] visit;
		queue.add(s);
		int max = 0;
		for (int i = 0; i < n; ++i) {
			visit = new boolean[m+1];
			for (int j = 0, size = queue.size(); j < size; ++j) {
				int k = queue.poll();
				int t = k + arr[i];
				if (t <= m && !visit[t]) {
					visit[t] = true;
					if (i == n-1)
						max = Math.max(t, max);
					queue.add(t);
				}
				t = k - arr[i];
				if (t >= 0 && !visit[t]) {
					visit[t] = true;
					if (i == n-1)
						max = Math.max(t, max);
					queue.add(t);
				}
			}
			if (queue.isEmpty()) {
				max = -1;
				break;
			}
		}
		System.out.print(max);
	}
}
