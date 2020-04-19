package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_G5_1405_미친로봇 {
	private static int n, v = 4;
	private static boolean[][] visit = new boolean[29][29];
	private static double[] dv = new double[v];
	private static int[][] di = {{0,1},{0,-1},{1,0},{-1,0}};
	private static double answer;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		n = Integer.parseInt(st.nextToken());
		for (int i = 0; i < v; ++i) {
			dv[i] = Integer.parseInt(st.nextToken()) / 100.0;
		}
		visit[14][14] = true;
		dfs(0,14,14,1);
		System.out.print(String.format("%.9f", answer));
		br.close();
	}
	
	private static void dfs(int depth, int sr, int sc, double cur) {
		if (depth == n) {
			answer += cur;
			return;
		}
		for (int d = 0; d < v; ++d) {
			int nr = sr + di[d][0];
			int nc = sc + di[d][1];
			if (!visit[nr][nc]) {
				visit[nr][nc] = true;
				dfs(depth+1, nr, nc, cur*dv[d]);
				visit[nr][nc] = false;
			}
		}
	}
}
