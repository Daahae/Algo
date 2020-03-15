import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_1916_G5_최소비용구하기 {
	private static int n, m, a, b;
	private static List<Move>[] graph;
	private static int[] dist;
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(bf.readLine());
		m = Integer.parseInt(bf.readLine());
		graph = new LinkedList[n];
		dist = new int[n];
		for (int i = 0; i < n; ++i) {
			graph[i] = new LinkedList<>();
			dist[i] = 1000000001; // 초기 시작 정점과의 거리 - 최대
		}
		for (int i = 0; i < m; ++i) {
			st = new StringTokenizer(bf.readLine(), " ");
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;
			int c = Integer.parseInt(st.nextToken());
			graph[a].add(new Move(b,c));
		}
		st = new StringTokenizer(bf.readLine(), " ");
		a = Integer.parseInt(st.nextToken())-1;
		b = Integer.parseInt(st.nextToken())-1;
		
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(a, 0));
		dist[a] = 0; // 시작 정점
		while (!pq.isEmpty()) {
			Node node = pq.poll();
			if (dist[node.i] < node.d) continue; // 이미 갱신된 상태
			for (Move m: graph[node.i]) {
				/* 연결된 정점 중 거리가 줄어들 수 있는 정점을 우선순위 큐에 추가
				 * 시작 정점과의 최단거리 갱신
				 */
				if (dist[m.n] > dist[node.i] + m.c) {
					dist[m.n] = dist[node.i] + m.c;
					pq.add(new Node(m.n, dist[m.n]));
				}
			}
		}
		System.out.print(dist[b]);
		bf.close();
	}
	
	static class Move {
		int n;
		int c;
		public Move(int n, int c) {
			this.n = n;
			this.c = c;
		}
	}
	
	static class Node implements Comparable<Node>{
		int i;
		int d;
		
		public Node(int i, int d) {
			this.i = i;
			this.d = d;
		}
		
		@Override
		public int compareTo(Node o) {
			if (d < o.d) {
				return -1;
			} else if (d == o.d) {
				return 0;
			} else {
				return 1;
			}
		}
	}
}
