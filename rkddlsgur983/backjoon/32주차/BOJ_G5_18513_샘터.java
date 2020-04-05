import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

/**
 * @{link}	https://www.acmicpc.net/problem/18513
 * @date   	2020-04-03
 * @author 	lolol0705
 * @memory 	57132KB / 256MB
 * @time   	496ms / 1초
 * @idea	BFS, 집의 범위가 아닌 샘터의 범위가 주어진 것 - 문제 제대로 읽어야함
 * 			최대 ans의 범위가 50000*50001이므로 Integer 범위를 넘어감
 */
public class BOJ_G5_18513_샘터 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		Queue<Integer> queue = new LinkedList<>();
		Set<Integer> set = new HashSet<>();
		st = new StringTokenizer(br.readLine(), " ");
		br.close();
		for (int i = 0; i < n; ++i) {
			int j = Integer.parseInt(st.nextToken());
			set.add(j);
			queue.add(j);
		}
		long ans = 0L;
		long step = 1L;
		int cnt = 0;
		while (!queue.isEmpty()) {
			for (int i = 0, size = queue.size(); i < size; ++i) {
				int j = queue.poll();
				if (!set.contains(j-1)) {
					set.add(j-1);
					queue.add(j-1);
					++cnt;
					ans += step;
					if (cnt == k) {
						System.out.print(ans);
						return;
					}
				}
				if (!set.contains(j+1)) {
					set.add(j+1);
					queue.add(j+1);
					++cnt;
					ans += step;
					if (cnt == k) {
						System.out.print(ans);
						return;
					}
				}
			}
			++step;
		}
	}
}
