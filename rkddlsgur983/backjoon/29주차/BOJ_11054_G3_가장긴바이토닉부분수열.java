import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_11054_G3_가장긴바이토닉부분수열 {
	private static int n;
	private static int[] arr;
	private static int[] left, right;
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(bf.readLine());
		arr = new int[n];
		left = new int[n];
		right = new int[n];
		StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
		
		for (int i = 0; i < n; ++i) {
			arr[i] = Integer.parseInt(st.nextToken());
			int max = 0;
			for (int j = 0; j < i; ++j) {
				if (arr[j] < arr[i]) {
					max = Math.max(left[j], max);
				}
			}
			left[i] = max+1;
		}
		int ans = 0;
		for (int i = n-1; i >= 0; --i) {
			int max = 0;
			for (int j = n-1; j > i; --j) {
				if (arr[j] < arr[i]) {
					max = Math.max(right[j], max);
				}
			}
			right[i] = max+1;
			ans = Math.max(left[i]+right[i]-1, ans);
		}
		System.out.print(ans);
		bf.close();
	}
}
