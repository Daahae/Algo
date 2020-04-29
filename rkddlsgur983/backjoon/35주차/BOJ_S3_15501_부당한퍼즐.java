package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @{link} 	https://www.acmicpc.net/problem/15501
 * @date   	2020-04-27
 * @author 	rkddlsgur983
 * @memory 	230244KB / 256MB
 * @time   	608ms / 2초
 * @idea	문제의 규칙에따라 정방향 or 역방향 배열의 범위 체크를 해주면서
 * 			입력배열과 결과배열이 일치하는지 확인한다.
 */
public class BOJ_S3_15501_부당한퍼즐 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st1 = new StringTokenizer(br.readLine(), " ");
		StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");
		int[] arr = new int[n], brr = new int[n];
		for (int i = 0; i < n; ++i) {
			arr[i] = Integer.parseInt(st1.nextToken());
			brr[i] = Integer.parseInt(st2.nextToken());
		}
		if (n == 1) {
			System.out.print("good puzzle");
			return;
		}
		
		boolean a = true, b = true;
		for (int i = 0; i < n; ++i) {
			if (arr[0] == brr[i]) {
				int j = i == n-1 ? 0 : i+1;
				if (arr[1] == brr[j]) {
					for (int k = 2; k < n; ++k) {
						j = j == n-1 ? 0 : j+1;
						if (arr[k] != brr[j]) {
							a = false;
							break;
						}
					}
				} else a = false;
				j = i == 0 ? n-1 : i-1;
				if (arr[1] == brr[j]) {
					for (int k = 2; k < n; ++k) {
						j = j == 0 ? n-1 : j-1;
						if (arr[k] != brr[j]) {
							b = false;
							break;
						}
					}
				} else b = false;
				if (a || b) System.out.print("good puzzle");
				else System.out.print("bad puzzle");
				return;
			}
		}
		System.out.print("bad puzzle");
	}
}
