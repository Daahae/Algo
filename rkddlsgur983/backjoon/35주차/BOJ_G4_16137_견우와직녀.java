package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * @{link} 	https://www.acmicpc.net/problem/16137
 * @date   	2020-04-29
 * @author 	rkddlsgur983
 * @memory 	13148KB / 256MB
 * @time   	76ms / 1초
 * @idea	시뮬레이션
 */
public class BOJ_G4_16137_견우와직녀 {
	private static int[][] di = {{0,1},{1,0},{0,-1},{-1,0}};
	private static int[][] ddi = {{0,1},{1,0},{0,-1},{-1,0},{0,1}};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][n];
		for (int i = 0; i < n; ++i) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < n; ++j) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		br.close();
		
		// 오작교를 놓을 수 없는 곳 -1
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j] == 0) {
					for (int d = 0; d < 4; ++d) {
						int ar = i + ddi[d][0];
						int ac = j + ddi[d][1];
						int cr = i + ddi[d+1][0];
						int cc = j + ddi[d+1][1];
						if (!isInRange(ar,ac,n) || !isInRange(cr,cc,n)) continue;
						if (map[ar][ac] != 1 && map[cr][cc] != 1) {
							map[i][j] = -1;
							break;
						}
					}
				}
			}
		}
		
		/* BFS
		 * weight: row / col / 오작교 사용
		 * move: row / col / 오작교 사용 / 이전에 오작교 밟음(2연속 X)
		 */
		int[][][] weight = new int[n][n][2];
		weight[0][0][0] = 0;
		Queue<Move> queue = new LinkedList<>();
		queue.add(new Move(0,0,0,false));
		while (!queue.isEmpty()) {
			Move v = queue.poll();
			for (int[] d: di) {
				int nr = v.r + d[0];
				int nc = v.c + d[1];
				if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
					if (map[nr][nc] == -1) continue;
					if (map[nr][nc] == 1) {
						if (weight[nr][nc][v.u] == 0 || weight[nr][nc][v.u] > weight[v.r][v.c][v.u]+1) {
							weight[nr][nc][v.u] = weight[v.r][v.c][v.u]+1;
							queue.add(new Move(nr,nc,v.u,false));
						}
					} else if (map[nr][nc] == 0) {
						if (v.u == 1 || v.j) continue;
						int k = weight[v.r][v.c][v.u];
						k = (k/m+1)*m;
						if (weight[nr][nc][1] == 0 || weight[nr][nc][1] > k) {
							weight[nr][nc][1] = k;
							queue.add(new Move(nr,nc,1,true));
						}
					} else {
						if (v.j) continue;
						int l = map[nr][nc];
						int k = weight[v.r][v.c][v.u];
						k = (k/l+1)*l;
						if (weight[nr][nc][v.u] == 0 || weight[nr][nc][v.u] > k) {
							weight[nr][nc][v.u] = k;
							queue.add(new Move(nr,nc,v.u,true));
						}
					}
				}
			}
		}
		System.out.print(Math.min(weight[n-1][n-1][0] == 0 ? Integer.MAX_VALUE : weight[n-1][n-1][0], weight[n-1][n-1][1] == 0 ? Integer.MAX_VALUE : weight[n-1][n-1][1]));
	}
	
	private static boolean isInRange(int r, int c, int n) {
		return r >= 0 && r < n && c >= 0 && c < n;
	}
	
	static class Move {
		int r;
		int c;
		int u;
		boolean j;
		public Move(int r, int c, int u, boolean j) {
			this.r = r;
			this.c = c;
			this.u = u;
			this.j = j;
		}
	}
}
