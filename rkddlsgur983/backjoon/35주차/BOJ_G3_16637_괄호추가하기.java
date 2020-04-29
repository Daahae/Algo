package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @{link}	https://www.acmicpc.net/problem/16637
 * @date   	2020-04-28
 * @author 	rkddlsgur983
 * @memory 	12912KB / 512MB
 * @time   	72ms / 0.5초
 * @idea	완전탐색
 */
public class BOJ_G3_16637_괄호추가하기 {
	private static int n;
	private static int[] arr;
	private static char[] orr;
	private static int max = Integer.MIN_VALUE;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		String s = br.readLine();
		br.close();
		arr = new int[n/2+1];
		orr = new char[n/2];
		for (int i = 0, j = 0, k = 0; i < n; ++i) {
			if (i%2==0) arr[j++] = s.charAt(i)-'0';
			else orr[k++] = s.charAt(i);
		}
		dfs(0, arr[0]);
		System.out.print(max);
	}
	
	private static void dfs(int depth, int v) {
		if (depth == n/2) {
			max = Math.max(v, max);
			return;
		}
		
		if (depth+1 < n/2) {
			dfs(depth+2, cal(v, cal(arr[depth+1], arr[depth+2], orr[depth+1]), orr[depth]));
		}
		dfs(depth+1, cal(v, arr[depth+1], orr[depth]));
	}
	
	private static int cal(int a, int b, char o) {
		switch(o) {
			case '+':
				return a+b;
			case '-':
				return a-b;
			case '*':
				return a*b;
		}
		return 0;
	}
}
