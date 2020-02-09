package day1;

import java.util.Scanner;

public class SWEA_1206_View {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= 10; i++) {
			sb.append("#").append(i).append(" ");
			int n = sc.nextInt();
			int[] arr = new int[n];
			for (int j = 0; j < n; j++) {
				arr[j] = sc.nextInt();
			}
			int sum = 0;
			for (int j = 2; j < n-2; j++) {
				int left = arr[j-2] < arr[j-1] ? arr[j-1] : arr[j-2];
				int right = arr[j+1] < arr[j+2] ? arr[j+2] : arr[j+1];
				int max = left < right ? right : left;
				int cnt = arr[j] - max;
				sum += cnt > 0 ? cnt : 0;
			}
			sb.append(sum).append("\n");
		}
		System.out.println(sb);
		sc.close();
	}
}
