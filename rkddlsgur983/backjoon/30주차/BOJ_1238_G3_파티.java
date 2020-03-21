import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_1238_G3_파티 {
	private static int n, m, x, max = 0;
	private static List<int[]>[] graph;
	private static int[] dist;
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken())-1;
		graph = new LinkedList[n];
		dist = new int[n];
		for (int i = 0; i < n; ++i) {
			graph[i] = new LinkedList<>();
		}
		for (int i = 0; i < m; ++i) {
			st = new StringTokenizer(bf.readLine(), " ");
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;
			int c = Integer.parseInt(st.nextToken());
			graph[a].add(new int[] {b,c});
		}
		bf.close();

	
		/* 다익스트라
 	 	 * i에서 x까지, x부터 i까지의 최단 이동시간 합을 구하고
 	 	 * 이들 중 가장 최대값이 가장 많은 시간을 소비하는 학생
	 	 */
		for (int i = 0; i < n; ++i) {
			max = Math.max(dijkstra(i,x)+dijkstra(x,i), max);
		}
		System.out.print(max);
	}

	private static int dijkstra(int start, int end) {

		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[start] = 0;
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[1], o2[1]);
			}
		});
		for (int[] j: graph[start]) {
			dist[j[0]] = j[1];
			pq.add(j);
		}
		
		while (!pq.isEmpty()) {
			int[] i = pq.poll();
			for (int[] j: graph[i[0]]) {
				if (dist[j[0]] > dist[i[0]] + j[1]) {
					dist[j[0]] = dist[i[0]] + j[1];
					pq.add(j);
				}
			}
		}
		return dist[end];
	}
}
