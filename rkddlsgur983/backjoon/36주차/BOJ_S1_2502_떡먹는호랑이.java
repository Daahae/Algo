package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @{link}	https://www.acmicpc.net/problem/2502
 * @date   	2020-04-29
 * @author 	rkddlsgur983
 * @memory 	13152KB / 128MB
 * @time   	76ms / 1초
 * @idea	동적 계획법, 피보나치
 */
public class BOJ_S1_2502_떡먹는호랑이 {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
		bf.close();
		int d = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[][] dp = new int[d+1][2];
		dp[1][0] = 1;
		dp[2][1] = 1;
		for (int i = 3; i <= d; ++i) {
			dp[i][0] = dp[i-1][0]+dp[i-2][0];
			dp[i][1] = dp[i-1][1]+dp[i-2][1];
		}
		int a = 1;
		while (true) {
			int t = k-dp[d][0]*a;
			if (t%dp[d][1] == 0) {
				System.out.printf("%d\n%d",a,t/dp[d][1]);
				return;
			}
			++a;
		}
	}
}
