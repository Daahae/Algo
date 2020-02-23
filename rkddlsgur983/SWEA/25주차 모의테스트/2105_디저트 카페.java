package day6;

import java.util.Scanner;

public class Solution {

	private static int[][] di = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
	private static int max = -1;
	public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
        	StringBuilder sb = new StringBuilder();
        	int t = sc.nextInt();
        	for (int i = 1; i <= t; i++) {
        		sb.append("#").append(i).append(" ");
    		int n = sc.nextInt();
    		int[][] map = new int[n][n];
    		for (int j = 0; j < n; j++) {
    			for (int k = 0; k < n; k++) {
    				map[j][k] = sc.nextInt();
    			}
    		}

    		boolean[][] visit = new boolean[n][n];
    		boolean[] check = new boolean[101];
    		max = -1;
    		for (int j = 0; j < n-1; j++) {
    			for (int k = 1; k < n-1; k++) {
    				check[map[j][k]] = true;
    				dfs(j,k,j,k,0,n,0,map, visit, check);
    				check[map[j][k]] = false;
    			}
    		}
    		sb.append(max).append("\n");    		
    	}
        	System.out.println(sb);
        	sc.close();
    }

	private static void dfs(int sr, int sc, int nr, int nc, int cnt, int n, int d, int[][] map, boolean[][] visit, boolean[] check) {

		for (int i = 0; i < 2; i++) {
			if (d+i == 4) return;
			int row = nr + di[d+i][0];
			int col = nc + di[d+i][1];
			if (isInRange(row, col, n) && !visit[row][col] && !check[map[row][col]]) {
				visit[row][col] = true;
				check[map[row][col]] = true;
				dfs(sr, sc, row, col, cnt+1, n, d+i, map, visit, check);
				check[map[row][col]] = false;
				visit[row][col] = false;
			} else if (row == sr && col == sc) {
				max = max < cnt+1 ? cnt+1 : max;
				return;
			}
		}
	}

	private static boolean isInRange(int row, int col, int n) {
		return row >= 0 && row < n && col >= 0 && col < n;
	}
}