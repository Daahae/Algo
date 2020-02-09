import java.util.Scanner;

public class Solution {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sb.append("#").append(i).append(" ");
			int n = sc.nextInt();
			int[][] map = new int[n][n];
			int sum = 0;
			for (int j = 0; j < n; j++) {
				char[] temp = sc.next().toCharArray();
				for (int k = 0; k < n; k++) {
					map[j][k] = temp[k] - '0';
				}
				if (j <= n/2) {
					for (int k = n/2-j; k <= n/2+j; k++) {
						sum += map[j][k];
					}
				} else {
					for (int k = n/2-(n-1-j); k <= n/2+(n-1-j); k++) {
						sum += map[j][k];
					}
				}
			}
			sb.append(sum).append("\n");
		}
		System.out.println(sb);
		sc.close();
	}
}
