import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= 10; i++) {
			int t = sc.nextInt();
			sb.append("#").append(t).append(" ");
			int[][] map = new int[100][100];
			
			int max = 0, crossx = 0, crossy = 0;
			for (int j = 0; j < 100; j++) {
				int sum = 0;
				for (int k = 0; k < 100; k++) {
					map[j][k] = sc.nextInt();
					sum += map[j][k];
					if (j == k) crossx += map[j][k];
					if (j == 99-k) crossy += map[j][k];
				}
				max = max < sum ? sum : max;
			}
			max = max < crossx ? crossx : max;
			max = max < crossy ? crossy : max;
			for (int j = 0; j < 100; j++) {
				int sum = 0;
				for (int k = 0; k < 100; k++) {
					sum += map[k][j];
				}
				max = max < sum ? sum : max;
			}
			sb.append(max).append("\n");
		}
		System.out.println(sb);
		sc.close();
	}
}
