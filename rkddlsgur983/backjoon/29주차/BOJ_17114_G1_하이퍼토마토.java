import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_17114_G1_하이퍼토마토 {
	private static int[][] di = {
			{1,0,0,0,0,0,0,0,0,0,0},{-1,0,0,0,0,0,0,0,0,0,0},
			{0,1,0,0,0,0,0,0,0,0,0},{0,-1,0,0,0,0,0,0,0,0,0},
			{0,0,1,0,0,0,0,0,0,0,0},{0,0,-1,0,0,0,0,0,0,0,0},
			{0,0,0,1,0,0,0,0,0,0,0},{0,0,0,-1,0,0,0,0,0,0,0},
			{0,0,0,0,1,0,0,0,0,0,0},{0,0,0,0,-1,0,0,0,0,0,0},
			{0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,-1,0,0,0,0,0},
			{0,0,0,0,0,0,1,0,0,0,0},{0,0,0,0,0,0,-1,0,0,0,0},
			{0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,-1,0,0,0},
			{0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,-1,0,0},
			{0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,-1,0},
			{0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,-1},
	};
	private static int n = 11;
	private static int[] s = new int[n];
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		for (int i = n-1; i >= 0; --i) {
			s[i] = Integer.parseInt(st.nextToken());
		}
		int[][][][][][][][][][][] map = new int[s[0]][s[1]][s[2]][s[3]][s[4]][s[5]][s[6]][s[7]][s[8]][s[9]][s[10]];
		Queue<int[]> queue = new LinkedList<>();
		int[] tomato = new int[s[0]];
		for (int a = 0; a < s[0]; ++a) {
			for (int b = 0; b < s[1]; ++b) {
				for (int c = 0; c < s[2]; ++c) {
					for (int d = 0; d < s[3]; ++d) {
						for (int e = 0; e < s[4]; ++e) {
							for (int f = 0; f < s[5]; ++f) {
								for (int g = 0; g < s[6]; ++g) {
									for (int h = 0; h < s[7]; ++h) {
										for (int i = 0; i < s[8]; ++i) {
											for (int j = 0; j < s[9]; ++j) {
												st = new StringTokenizer(bf.readLine());
												for (int k = 0; k < s[10]; ++k) {
													map[a][b][c][d][e][f][g][h][i][j][k] = Integer.parseInt(st.nextToken());
													if (map[a][b][c][d][e][f][g][h][i][j][k] == 1) {
														queue.add(new int[] {a,b,c,d,e,f,g,h,i,j,k}); // 익은 토마토의 위치를 큐에 추가
													} else if (map[a][b][c][d][e][f][g][h][i][j][k] == 0){
														++tomato[a]; // 익지 않은 토마토
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		bf.close();
		int day = 1;
		int[] ns = new int[n];
		while (!queue.isEmpty()) {
			int[] ts = queue.poll();
			for (int d = 0; d < di.length; ++d) {
				for (int i = 0; i < n; ++i) {
					ns[i] = ts[i] + di[d][i];
				}
				if (isInRange(ns) && map[ns[0]][ns[1]][ns[2]][ns[3]][ns[4]][ns[5]][ns[6]][ns[7]][ns[8]][ns[9]][ns[10]] == 0) {
					map[ns[0]][ns[1]][ns[2]][ns[3]][ns[4]][ns[5]][ns[6]][ns[7]][ns[8]][ns[9]][ns[10]] 
							= map[ts[0]][ts[1]][ts[2]][ts[3]][ts[4]][ts[5]][ts[6]][ts[7]][ts[8]][ts[9]][ts[10]]+1; // 토마토가 익어갈 때마다 소요된 시간 추가
					int[] add = ns.clone();
					queue.add(add);
					--tomato[ns[0]];
					day = Math.max(map[ns[0]][ns[1]][ns[2]][ns[3]][ns[4]][ns[5]][ns[6]][ns[7]][ns[8]][ns[9]][ns[10]], day);
				}
			}
		}

		for (int i = 0; i < s[0]; ++i) {
			if (tomato[i] > 0) {
				System.out.print(-1);
				return;
			}
		}
		System.out.print(day-1);
	}
	
	private static boolean isInRange(int[] ns) {
		for (int i = 0; i < n; ++i) {
			if (ns[i] < 0 || ns[i] >= s[i]) {
				return false;
			}
		}
		return true;
	}
}
