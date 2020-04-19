package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ_S2_2841_외계인의기타연주 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		int s = 6;
		Stack<Integer>[] stack = new Stack[s];
		for (int i = 0; i < s; ++i) {
			stack[i] = new Stack<>();
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			st = new StringTokenizer(br.readLine(), " ");
			int j = Integer.parseInt(st.nextToken())-1;
			int k = Integer.parseInt(st.nextToken());
			while (!stack[j].isEmpty() && stack[j].peek() > k) {
				stack[j].pop();
				++cnt;
			}
			if (stack[j].isEmpty() || stack[j].peek() < k) {
				stack[j].add(k);
				++cnt;
			}
		}
		System.out.print(cnt);
		br.close();
	}
}
