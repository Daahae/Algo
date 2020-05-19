package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_G5_2467_용액 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; ++i) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		br.close();

		int min = Integer.MAX_VALUE;
		int t1 = 0, t2 = 0;
		for (int i = 0; i < n; ++i) {
			// 자신 기준 오른쪽 용액을 대상으로 이진탐색
			int a = i+1, b = n-1;
			while (a <= b) {
				int m = (a+b)/2;
				int v = Math.abs(arr[i] + arr[m]);
				// 최소가 되는 특성 값을 찾았다면 갱신
				if (min > v) {
					min = v;
					t1 = arr[i];
					t2 = arr[m];
				}
				/* 이 문제의 목적은 자신과 더했을 때 
				 * 절댓값이 0이 나오는 가장 가까운 위치를 찾는 것입니다.
				 * 따라서 '자신의 값에 대한 음의 값'과 가장 가까운 위치를 찾는다면
				 * 0과 근사한 결과를 얻을 수 있습니다.
				 */
				if (arr[m] == -arr[i]) {
					break;
				} else if (arr[m] < -arr[i]) {
					a = m+1;
				} else {
					b = m-1;
				}
			}
		}
		System.out.printf("%d %d", t1, t2);
	}
}
