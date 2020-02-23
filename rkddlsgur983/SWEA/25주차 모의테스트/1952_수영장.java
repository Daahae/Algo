package day6;

import java.util.Scanner;

public class SWEA_1952_수영장 {
	
	private static boolean[][] ticket = new boolean[4][12];
	private static int MIN = Integer.MAX_VALUE;
	private static int[] cost = new int[4];
	private static int[] plan = new int[12];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sb.append("#").append(i).append(" ");
			for (int j = 0; j < 4; j++) {
				cost[j] = sc.nextInt();
			}
			for (int j = 0; j < 12; j++) {
				plan[j] = sc.nextInt();
			}
			MIN = cost[3];
			bruteForce(0, 0, false, 0);
			sb.append(MIN).append("\n");
		}
		System.out.println(sb);
		sc.close();
	}
	
	private static void bruteForce(int month, int fee, boolean three, int cnt) {
		
		if (MIN <= fee) {
			return;
		} else if (month == 12) {
			MIN = fee;
			return;
		}
		if (plan[month] == 0) {
			bruteForce(month+1, fee, three, cnt);
			return;
		}
		
		if (three) {
			if (cnt == 2) {
				bruteForce(month+1, fee, false, 0);
			} else {
				bruteForce(month+1, fee, true, 2);
			}
		} else {
			bruteForce(month+1, fee+cost[0]*plan[month], three, cnt);
			bruteForce(month+1, fee+cost[1], three, cnt);
			bruteForce(month+1, fee+cost[2], true, 1);
		}
	}
}
