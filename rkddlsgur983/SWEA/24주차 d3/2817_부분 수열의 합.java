import java.util.Scanner;

class Solution {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sb.append("#").append(i).append(" ");
			int n = sc.nextInt();
			int k = sc.nextInt();
			int[] arr = new int[n];
			for (int j = 0; j < n; j++) {
				arr[j] = sc.nextInt();
			}
			
			int ans = 0;
			for (int j = 0; j < (1<<n); j++) {
				int sum = 0;
				for (int l = 0; l < n; l++) {
					if ((j & (1<<l)) > 0)  {
						sum += arr[l];
					}
				}
				if (k == sum) ans++;
			}
			sb.append(ans).append("\n");
		}
		System.out.println(sb);
		sc.close();
	}
}