import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14719_S1_빗물 {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		int h = Integer.parseInt(st.nextToken());
		int w = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(bf.readLine());
		int[] arr = new int[w];
		int[] left = new int[w];
		int[] right = new int[w];
		
		// i기준 왼쪽에서 가장 큰 높이를 left[i]에 저장
		int max = 0;
		for (int i = 0; i < w; ++i) {
			arr[i] = Integer.parseInt(st.nextToken());
			left[i] = max;
			max = max < arr[i] ? arr[i] : max;
		}
		// i기준 오른쪽에서 가장 큰 높이를 right[i]에 저장
		max = 0;
		for (int i = w-1; i >= 0; --i) {
			right[i] = max;
			max = max < arr[i] ? arr[i] : max;
		}

		int sum = 0;
		for (int i = 0; i < w; ++i) {
			// arr[i]가 left와 right의 큰 높이보다 커야함
			if (arr[i] < left[i] && arr[i] < right[i]) {
				// 그 중 작은 높이에서 현재 높이를 빼주면 빗물이 고이는 양
				int min = left[i] > right[i] ? right[i] : left[i];
				sum += min - arr[i];
			}
		}
		System.out.print(sum);
		bf.close();
	}
}
