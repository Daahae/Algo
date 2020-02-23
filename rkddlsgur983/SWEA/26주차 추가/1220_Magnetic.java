import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D3_1220_Magnetic {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int N = 100;
		int[][] map = new int[N][N];
		for (int i = 1; i <= 10; ++i) {
			int n = Integer.parseInt(bf.readLine());
			for (int j = 0; j < N; ++j) {
				st = new StringTokenizer(bf.readLine());
				for (int k = 0; k < N; ++k) {
					map[j][k] = Integer.parseInt(st.nextToken());
				}
			}
			int cnt = 0;
			for (int j = 0; j < N; ++j) {
				boolean north = false;
				for (int k = 0; k < N; ++k) {
					if (map[k][j] == 1) {
						north = true;
					}
					if (north && map[k][j] == 2) {
						++cnt;
						north = false;
					}
				}
			}
			sb.append("#").append(i).append(" ").append(cnt).append("\n");
		}
		System.out.print(sb);
		bf.close();
	}
}
