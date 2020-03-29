import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_G2_2252_줄세우기 {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		List<Integer>[] graph = new LinkedList[n];
		int[] cnt = new int[n];
		for (int i = 0; i < n; ++i) {
			graph[i] = new LinkedList<>();
		}
		for (int i = 0; i < m; ++i) {
			st = new StringTokenizer(bf.readLine(), " ");
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;
			graph[a].add(b);
			++cnt[b];
		}
		bf.close();
		
		Queue<Integer> queue = new LinkedList<>();
		for (int i = 0; i < n; ++i) {
			if (cnt[i] == 0) {
				queue.add(i);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		while (!queue.isEmpty()) {
			int i = queue.poll();
			sb.append(i+1).append(" ");
			while (!graph[i].isEmpty()) {
				int j = graph[i].remove(0);
				--cnt[j];
				if (cnt[j] == 0) {
					queue.add(j);
				}
			}
		}
		System.out.print(sb);
	}
}
