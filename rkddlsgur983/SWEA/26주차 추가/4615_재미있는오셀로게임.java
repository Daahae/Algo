import java.util.Scanner;

public class D3_4615_재미있는오셀로게임 {
	private static int[][] di = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int t = sc.nextInt();
		for (int i = 1; i <= t; ++i) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[][] map = new int[n+1][n+1];
			map[n/2][n/2] = 2;
			map[n/2][n/2+1] = 1;
			map[n/2+1][n/2] = 1;
			map[n/2+1][n/2+1] = 2;
			int[] rock = {0,2,2};
			for (int j = 0; j < m; ++j) {
				int row = sc.nextInt();
				int col = sc.nextInt();
				int color = sc.nextInt();
				map[row][col] = color;
				++rock[color];
				for (int d = 0; d < di.length; ++d) {
					int nr = row + di[d][0];
					int nc = col + di[d][1];
					while (isInRange(nr,nc,n) 
							&& map[nr][nc] != 0 
							&& map[nr][nc] != color) {
						nr += di[d][0];
						nc += di[d][1];
					}
					if (isInRange(nr,nc,n) && map[nr][nc] == color) {
						nr = row + di[d][0];
						nc = col + di[d][1];
						while (isInRange(nr,nc,n) 
								&& map[nr][nc] != 0 
								&& map[nr][nc] != color) {
							--rock[map[nr][nc]];
							map[nr][nc] = color;
							++rock[color];
							nr += di[d][0];
							nc += di[d][1];
						}
					}
				}
			}
			sb.append("#").append(i).append(" ")
			.append(rock[1]).append(" ")
			.append(rock[2]).append("\n");
		}
		System.out.print(sb);
		sc.close();
	}
	private static boolean isInRange(int row, int col, int n) {
		return row > 0 && row <= n && col > 0 && col <= n;
	}
}
