import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_1005_G3_ACMCraft {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int t = Integer.parseInt(bf.readLine());
		int[] arr = new int[1000];
		for (int i = 0; i < t; ++i) {
			st = new StringTokenizer(bf.readLine(), " ");
			int n = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(bf.readLine(), " ");
			List<Integer>[] before = new LinkedList[n];
			List<Integer>[] after = new LinkedList[n];
			for (int j = 0; j < n; ++j) {
				arr[j] = Integer.parseInt(st.nextToken());
				before[j] = new LinkedList<>();
				after[j] = new LinkedList<>();
			}
			for (int j = 0; j < k; ++j) {
				st = new StringTokenizer(bf.readLine(), " ");
				int a = Integer.parseInt(st.nextToken())-1;
				int b = Integer.parseInt(st.nextToken())-1;
				if (arr[a] > 0) { // 이미 건설되어 있으면 이전 순서와 관계없음
					before[b].add(a); // b 이전에 건설되어야 하는 a
					after[a].add(b); // a가 건설되어야하는 b
				}
			}
			int w = Integer.parseInt(bf.readLine())-1;
			int ans = 0;
			if (arr[w] > 0) { // 이미 건설되어있으면 종료
				PriorityQueue<Build> queue = new PriorityQueue<>();
				List<Build> tmp = new LinkedList<>();
				for (int j = 0; j < n; ++j) {
					// j 이전에 건설되어야 하는 것들이 없다면 j가 건설되어야 함
					if (before[j].isEmpty() && arr[j] > 0) {
						queue.add(new Build(j, arr[j]));
					}
				}
				here: while (!queue.isEmpty()) {
					// 건설되어야 하는 건물들 중 가장 적게 소요되는 시간
					int time = queue.peek().t;
					ans += time;
					for (int j = 0, size = queue.size(); j < size; ++j) {
						Build b = queue.poll();
						int build = b.i;
						b.t -= time;
						arr[build] -= time;
						// 건설이 완료되었을 때
						if (arr[build] == 0) {
							// w라면 종료
							if (build == w) {
								break here;
							}
							// 건설 완료된 build 다음에 건설되어야 하는 건물들 확인
							for (Integer a: after[build]) {
								before[a].remove(Integer.valueOf(build)); // 연결 관계 제거
								if (before[a].isEmpty() && arr[a] > 0) {
									tmp.add(new Build(a, arr[a])); // 다음 건설 타겟 추가
								}
							}
							after[build].clear();
						} else {
							tmp.add(b); // 이어서 건설
						}
					}
					/* 새로 추가된 건물이 가장 낮은 경우
					 * 먼저 poll될 수 있기 때문에 임시 리스트 사용
					 */
					queue.addAll(tmp);
					tmp.clear();
				}
			}
			sb.append(ans).append("\n");
		}
		System.out.print(sb);
		bf.close();
	}
	
	static class Build implements Comparable<Build> {
		int i;
		int t;
		
		public Build(int i, int t) {
			this.i = i;
			this.t = t;
		}

		@Override
		public int compareTo(Build o) {
			if (t < o.t) {
				return -1;
			} else if (t == o.t) {
				return 0;
			} else {
				return 1;
			}
		}
	}
}
