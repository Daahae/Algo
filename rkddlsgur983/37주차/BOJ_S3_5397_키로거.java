package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/**
 * @{link}	https://www.acmicpc.net/problem/5397
 * @date   	2020-05-07
 * @author 	rkddlsgur983
 * @memory 	244184KB / 256MB
 * @time   	1100ms / 1초
 * @idea	ArrayList와 LinkedList 모두 
 * 			인덱스를 대상으로의 add or remove 연산의 빅오가 O(n)이므로 시간초과
 * 			스택 두개를 사용해서 커서를 관리하면 해결할 수 있다.
 */
public class BOJ_S3_5397_키로거 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int tc = Integer.parseInt(br.readLine());
		for (int t = 0; t < tc; ++t) {
			String s = br.readLine();
			Stack<Character> head = new Stack<>();
			Stack<Character> tail = new Stack<>();
			for (int i = 0, len = s.length(); i < len; ++i) {
				switch (s.charAt(i)) {
					case '<':
						if (!head.isEmpty()) {
							tail.add(head.pop());
						}
						break;
					case '>':
						if (!tail.isEmpty()) {
							head.add(tail.pop());
						}
						break;
					case '-':
						if (!head.isEmpty()) {
							head.pop();
						}
						break;
					default:
						head.add(s.charAt(i));
						break;
				}
			}
			while (!head.isEmpty()) {
				tail.add(head.pop());
			}
			while (!tail.isEmpty()) {
				sb.append(tail.pop());
			}
			sb.append("\n");
		}
		System.out.print(sb);
		br.close();
	}
}
