package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_S4_10989_수정렬하기3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] arr = new int[10001];
		int n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; ++i) {
			++arr[Integer.parseInt(br.readLine())];
		}
		br.close();
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= 10000; ++i) {
			while (arr[i] > 0) {
				--arr[i];
				sb.append(i).append("\n");
				--n;
			}
			if (n == 0) break;
		}
		System.out.print(sb);
	}
}
