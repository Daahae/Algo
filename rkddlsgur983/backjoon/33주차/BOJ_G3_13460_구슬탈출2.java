import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @{link}	https://www.acmicpc.net/problem/13460
 * @date   	2020-04-12
 * @author 	rkddlsgur983
 * @memory 	18508KB / 512MB
 * @time   	276ms / 2초
 * @idea	시뮬레이션
 */
public class BOJ_G3_13460_구슬탈출2 {
	private static int n, m;
	private static char[][] map;
	private static int possible, min = 11;
	private static int[][] di = {{0,1},{1,0},{0,-1},{-1,0}};
	private static int rer, rec;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new char[n][m];
		int redr = 0, redc = 0, bluer = 0, bluec = 0;
		for (int i = 0; i < n; ++i) {
			String s = br.readLine();
			for (int j = 0; j < m; ++j) {
				map[i][j] = s.charAt(j);
				if (map[i][j] == 'R') {
					redr = i;
					redc = j;
					map[i][j] = '.';
				}
				if (map[i][j] == 'B') {
					bluer = i;
					bluec = j;
					map[i][j] = '.';
				}
			}
		}
		br.close();
		dfs(0, redr, redc, bluer, bluec);
		System.out.print(min == 11 ? -1 : min+1);
	}
	
	private static void dfs(int depth, int redr, int redc, int bluer, int bluec) {
		if (min <= depth || depth == 10) {
			return;
		}
		
		for (int d = 0; d < 4; ++d) {
			if (min <= depth) return;
			if (!move(bluer, bluec, d, false)) {
				continue;
			}
			int nbr = rer;
			int nbc = rec;
			move(redr, redc, d, true);
			if (possible == 1) {
				min = depth;
				possible = 0;
				return;
			}
			int nrr = rer;
			int nrc = rec;
			if (nrr == nbr && nrc == nbc) {
				if (d == 0) {
					if (redc < bluec) --nrc;
					else --nbc;
				} else if (d == 1) {
					if (redr < bluer) --nrr;
					else --nbr;
				} else if (d == 2) {
					if (redc < bluec) ++nbc;
					else ++nrc;
				} else if (d == 3) {
					if (redr < bluer) ++nbr;
					else ++nrr;
				}
			}
			dfs(depth+1, nrr, nrc, nbr, nbc);
		}
	}
	
	private static boolean move(int r, int c, int d, boolean color) {

		int nr = r;
		int nc = c;
		while (nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] != '#') {
			if (map[nr][nc] == '.') {
				rer = nr;
				rec = nc;
				nr += di[d][0];
				nc += di[d][1];
			} else {
				if (color) {
					possible = 1;
					return true;
				} else {
					return false;
				}
			}
		}
		return true;
	}
}
