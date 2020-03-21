import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BOJ_1697_S1_숨바꼭질 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		sc.close();
		boolean[] visit = new boolean[100001];
		Queue<Integer> queue = new LinkedList<>();
		queue.add(n);
		visit[n] = true;
		// BFS
		for (int time = 0; !queue.isEmpty(); ++time) {
			for (int i = 0, size = queue.size(); i < size; ++i) {
				int s = queue.poll();
				if (s == k) {
					System.out.print(time);
					return;
				}
				if (s - 1 >= 0 && !visit[s-1]) {
					queue.add(s-1);
					visit[s-1] = true;
				}
				if (s + 1 <= 100000 && !visit[s+1]) {
					queue.add(s+1);
					visit[s+1] = true;
				}
				if (2*s <= 100000 && !visit[2*s]) {
					queue.add(2*s);
					visit[2*s] = true;
				}
			}
		}
	}
}
