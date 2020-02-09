import java.util.Arrays;
import java.util.Scanner;

class Solution {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= 10; i++) {
			sb.append("#").append(i).append(" ");
			int dump = sc.nextInt();
			int[] arr = new int[100];
			for (int j = 0; j < 100; j++) {
				arr[j] = sc.nextInt();
			}
			for (int j = 0; j < dump; j++) {
				Arrays.sort(arr);
				arr[0] += 1;
				arr[99] -= 1;
			}
			Arrays.sort(arr);
			sb.append(arr[99]-arr[0]);
			sb.append("\n");
		}
		System.out.println(sb);
		sc.close();
	}
}