import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class G5_17471_게리맨더링 {
	private static int min = Integer.MAX_VALUE;
	private static int[] arr; // 선거구 인구수
	private static List<Integer>[] graph; // 연결된 구역정보
	private static boolean[] sep; // 선거구 분리
	private static Queue<Integer> queue = new LinkedList<>();
	private static boolean[] visit;
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bf.readLine());
		arr = new int[n];
		sep = new boolean[n];
		visit = new boolean[n];
		StringTokenizer st = new StringTokenizer(bf.readLine());
		for (int i = 0; i < n; ++i) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		graph = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			graph[i] = new ArrayList<>();
			st = new StringTokenizer(bf.readLine());
			int g = Integer.parseInt(st.nextToken());
			for (int j = 0; j < g; ++j) {
				graph[i].add(Integer.parseInt(st.nextToken())-1);
			}
		}
		
		/* 1~n/2개 선거구 연결
		 */
		for (int i = 1; i <= n/2; ++i) {
			dfs(0, 0, i, n);
		}
		if (min == Integer.MAX_VALUE)
			min = -1;
		System.out.print(min);
		bf.close();
	}
	
	private static void dfs(int start, int current, int depth, int n) {
		
		if (current == depth) {
			/* 2개로 나누어 졌는지 확인
			 * 최솟값 찾기
			 */
			Arrays.fill(visit, false); // 검사이전 방문여부 초기화
			int cnt = 0; // 분리된 선거구 개수 -> 3개 이상이면 실패
			int asum = 0, bsum = 0; // a,b 선거구 인구수
			for (int i = 0; i < n; ++i) {
				if (!visit[i]) {
					if (cnt == 2) return; // 선거구 2개일때 다른 선거구가 있으면 실패
					int tsum = 0;
					visit[i] = true;
					queue.add(i);
					while (!queue.isEmpty()) {
						int idx = queue.poll();
						tsum += arr[idx];
						for (Integer g: graph[idx]) {
							if (sep[i] == sep[g] && !visit[g]) {
								visit[g] = true;
								queue.add(g);
							}
						}
					}
					++cnt;
					if (cnt == 1) {
						asum = tsum;
					} else if (cnt == 2) {
						bsum = tsum;
					}
				}
			}
			if (cnt == 2) {
				int m = Math.abs(asum-bsum);
				min = min > m ? m : min;
			}
			return;
		}
		
		for (int i = start; i < n; ++i) {
			sep[i] = true;
			dfs(i+1, current+1, depth, n);
			sep[i] = false;
		}
	}
}
