import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_G5_1600_말이되고픈원숭이 {
	private static int[][] horse = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
	private static int[][] di = {{0,1},{1,0},{0,-1},{-1,0}};
	public static void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int k = Integer.parseInt(bf.readLine());
		StringTokenizer st = new StringTokenizer(bf.readLine());
		int w = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		boolean[][] map = new boolean[h][w];
		for (int i = 0; i < h; i++) {
			st = new StringTokenizer(bf.readLine());
			for (int j = 0; j < w; j++) {
				map[i][j] = Integer.parseInt(st.nextToken()) == 1;
			}
		}
		bf.close();
		if (h == 1 && w == 1) {
			System.out.print(0);
			return;
		}
		
		Queue<int[]> queue = new LinkedList<>();
		boolean[][][] visit = new boolean[h][w][k+1];
		visit[0][0][0] = true;
		queue.add(new int[] {0,0,0});
		int step = 0;
		while(!queue.isEmpty()) {
			++step;
			for (int i = 0, size = queue.size(); i < size; ++i) {
				int[] m = queue.poll();
				if (m[2] < k) {
					for (int[] hor: horse) {
						int nr = m[0] + hor[0];
						int nc = m[1] + hor[1];
						if (nr >= 0 && nr < h && nc >= 0 && nc < w
								&& !map[nr][nc]
								&& !visit[nr][nc][m[2]+1]) {
							if (nr == h-1 && nc == w-1) {
								System.out.print(step);
								return;
							}
							visit[nr][nc][m[2]+1] = true;
							queue.add(new int[] {nr,nc,m[2]+1});
						}
					}
				}
				for (int[] d: di) {
					int nr = m[0] + d[0];
					int nc = m[1] + d[1];
					if (nr >= 0 && nr < h && nc >= 0 && nc < w
							&& !map[nr][nc]
							&& !visit[nr][nc][m[2]]) {
						if (nr == h-1 && nc == w-1) {
							System.out.print(step);
							return;
						}
						visit[nr][nc][m[2]] = true;
						queue.add(new int[] {nr,nc,m[2]});
					}
				}
			}
		}
		System.out.print(-1);
	}
}