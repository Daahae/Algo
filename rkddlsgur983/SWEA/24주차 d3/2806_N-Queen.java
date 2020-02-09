import java.util.Scanner;

public class Solution {

	private static int count;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sb.append("#").append(i).append(" ");
			int n = sc.nextInt();
			count = 0;
			bruteForce(1, n, new int[n+1]);
			sb.append(count).append("\n");
		}
		System.out.println(sb);
		sc.close();
	}
	
	private static void bruteForce(int row, int n, int[] queen) {
		
		if (row == n+1) {
			count++;
			return;
		}
		
		for (int j = 1; j <= n; j++) {
			int index = possible(row,j,n,queen);
			if (index > 0) {
				queen[index] = j;
				bruteForce(row+1, n, queen);
				queen[index] = 0;
			}
		}
	}
	
	private static int possible(int row, int col, int n, int[] queen) {
		for (int i = 1; i <= n; i++) {
			if (queen[i] == 0) 
				return i;
			if (queen[i] == col) // 행 or 열 같으면
				return 0;
			if (Math.abs(i-row) == Math.abs(queen[i]-col)) // 대각선
				return 0;
		}
		return 0;
	}
}
