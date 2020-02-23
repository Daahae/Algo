package day6;

import java.util.Scanner;

public class SWEA_1949_등산로조성 {
	
	private static int[][] di = {{0,1},{1,0},{0,-1},{-1,0}};
	private static int depth;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sb.append("#").append(i).append(" ");
			int n = sc.nextInt();
			int k = sc.nextInt();
			int[][] map = new int[n][n];
			int max = 0;
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < n; l++) {
					map[j][l] = sc.nextInt();
					max = max < map[j][l] ? map[j][l] : max;
				}
			}
			int[][] top = new int[6][2];
			int tidx = 0;
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < n; l++) {
					if (map[j][l] == max) {
						top[tidx][0] = j;
						top[tidx][1] = l;
						tidx++;
					}
				}
			}
			depth = 0;
			for (int o = 0; o < tidx; o++) {
				int row = top[o][0];
				int col = top[o][1];
				dfs(row, col, n, 1, map); // 원상태
				for (int j = 0; j < n; j++) {
					for (int l = 0; l < n; l++) {
						if (row == j && col == l)
							continue;
						for (int h = k; h >= 1; h--) {
							map[j][l] -= h;
							dfs(row, col, n, 1, map);
							map[j][l] += h;
						}
					}
				}
			}
			sb.append(depth).append("\n");
		}
		System.out.println(sb);
		sc.close();
	}
	
	private static void dfs(int row, int col, int n, int dep, int[][] map) {
		
		depth = depth < dep ? dep : depth;
		for (int d = 0; d < di.length; d++) {
			int nr = row + di[d][0];
			int nc = col + di[d][1];
			if (isInRange(nr, nc, n) && map[row][col] > map[nr][nc]) {
				dfs(nr, nc, n, dep+1, map);
			}
		}
	}
	
	private static boolean isInRange(int row, int col, int n) {
		return row >= 0 && row < n && col >= 0 && col < n;
	}
}
