import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @{link}	https://www.acmicpc.net/problem/12865
 * @date   	2020-03-31
 * @author 	rkddlsgur983
 * @memory 	53076KB / 512MB
 * @time   	176ms / 2초
 * @idea	Knapsack 알고리즘, 메모이제이션
 */
public class BOJ_G5_12865_평범한배낭 {
	private static int n, k;
	private static int[][] arr;
	private static int[][] memo;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		arr = new int[n][2];
		memo = new int[n][100001];
		for (int i = 0; i < n; ++i) {
			st = new StringTokenizer(br.readLine(), " ");
			int w = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			arr[i][0] = w;
			arr[i][1] = v;
		}
		System.out.print(dfs(0, 0));
		br.close();
	}
	
	private static int dfs(int depth, int w) {
		if (depth == n) {
			return 0;
		}
		if (memo[depth][w] != 0) {
			return memo[depth][w];
		}
		
		int tmp = 0;
		if (w + arr[depth][0] <= k) {
			tmp = dfs(depth+1, w + arr[depth][0]) + arr[depth][1];
		}
		tmp = Math.max(dfs(depth+1, w), tmp);
		return memo[depth][w] = tmp;
	}
}
