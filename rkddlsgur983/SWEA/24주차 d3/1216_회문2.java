import java.util.Scanner;

public class Solution {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= 10; i++) {
			int t = sc.nextInt();
			sb.append("#").append(t).append(" ");
			char[][] map = new char[100][100];
			int max = 1;
			for (int j = 0; j < 100; j++) { // 가로
				map[j] = sc.next().toCharArray();
				for (int k = 0; k < 100-max; k++) {
					for (int l = max+1; l <= 100-k; l++) {
						int cnt = 0;
						for (int m = 0; m < Math.ceil(l/2.0); m++) {
							if (map[j][k+m] == map[j][k+l-1-m]) {
								cnt++;
							} else {
								break;
							}
						}
						if (cnt == Math.ceil(l/2.0)) 
							max = max < l ? l : max;
					}
				}
			}
			
			for (int j = 0; j < 100; j++) { // 세로
				for (int k = 0; k < 100-max; k++) {
					for (int l = max+1; l <= 100-k; l++) {
						int cnt = 0;
						for (int m = 0; m < Math.ceil(l/2.0); m++) {
							if (map[k+m][j] == map[k+l-1-m][j]) {
								cnt++;
							} else {
								break;
							}
						}
						if (cnt == Math.ceil(l/2.0)) 
							max = max < l ? l : max;
					}
				}
			}
			sb.append(max).append("\n");
		}
		System.out.println(sb);
		sc.close();
	}
}
