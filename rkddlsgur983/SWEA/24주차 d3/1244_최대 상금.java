import java.util.Scanner;

public class SWEA_1244_최대상금 {

	private static int max = 0;
	private static int n = 0;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sb.append("#").append(i).append(" ");
			char[] num = sc.next().toCharArray();
			n = sc.nextInt();
			bruteForce(0, 0, num);
			sb.append(max).append("\n");
			max = 0;
		}
		System.out.println(sb);
		sc.close();
	}
	
	private static void bruteForce(int cnt, int index, char[] num) {
		
		if (cnt == n) {
			max = Math.max(max, Integer.parseInt(String.valueOf(num)));
			return;
		}
		
		for (int i = index; i < num.length-1; i++) {
			for (int j = i+1; j < num.length; j++) {
				if (num[i] <= num[j]) {
					char temp = num[i];
					num[i] = num[j];
					num[j] = temp;
					bruteForce(cnt+1, i, num);
					num[j] = num[i];
					num[i] = temp;
				}
			}
		}
	}
}
