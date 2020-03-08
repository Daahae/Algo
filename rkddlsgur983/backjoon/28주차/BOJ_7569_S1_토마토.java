import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_7569_S1_토마토 {
	private static int[][] di = {{1,0,0},{-1,0,0},{0,0,1},{0,1,0},{0,0,-1},{0,-1,0}};
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		int[][][] map = new int[h][n][m]; // 높이, 세로, 가로
		Queue<Integer> queue = new LinkedList<>();
		int[] tomato = new int[h];
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < n; ++j) {
				st = new StringTokenizer(bf.readLine());
				for (int k = 0; k < m; ++k) {
					map[i][j][k] = Integer.parseInt(st.nextToken());
					if (map[i][j][k] == 1) { // 익은 토마토의 위치를 큐에 추가
						queue.add(i);
						queue.add(j);
						queue.add(k);
					} else if (map[i][j][k] == 0){
						++tomato[i]; // 익지 않은 토마토
					}
				}
			}
		}
		bf.close();

		int day = 1;
		while (!queue.isEmpty()) {
			int hei = queue.poll();
			int row = queue.poll();
			int col = queue.poll();
			for (int d = 0; d < di.length; ++d) {
				int nh = hei + di[d][0];
				int nr = row + di[d][1];
				int nc = col + di[d][2];
				if (isInRange(nh,nr,nc,h,n,m) && map[nh][nr][nc] == 0) {
					map[nh][nr][nc] = map[hei][row][col]+1; // 토마토가 익어갈 때마다 소요된 시간 추가
					queue.add(nh);
					queue.add(nr);
					queue.add(nc);
					--tomato[nh];
					day = day < map[nh][nr][nc] ? map[nh][nr][nc] : day;
				}
			}
		}

		for (int i = 0; i < h; ++i) {
			if (tomato[i] > 0) {
				System.out.print(-1);
				return;
			}
		}
		System.out.print(day-1);
	}
	
	private static boolean isInRange(int hei, int row, int col, int h, int n, int m) {
		return hei >= 0 && hei < h && row >= 0 && row < n && col >= 0 && col < m;
	}
}
