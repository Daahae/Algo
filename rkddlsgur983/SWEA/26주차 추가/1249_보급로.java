import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class SWEA_1249_보급로 {
    private static int[][] di = {{0,1},{1,0},{0,-1},{-1,0}};
     
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            sb.append("#").append(i).append(" ");
            int n = sc.nextInt();
            char[][] map = new char[n][n];
            for (int j = 0; j < n; j++) {
                map[j] = sc.next().toCharArray();
            }
            int[][] weight = new int[n][n];
            for (int j = 0; j < n; j++) {
                Arrays.fill(weight[j], Integer.MAX_VALUE);
            }
            int min = Integer.MAX_VALUE;
            Queue<Integer> queue = new LinkedList<Integer>();
            queue.offer(0);
            queue.offer(0);
            queue.offer(0);
            while (!queue.isEmpty()) {
                int row = queue.poll();
                int col = queue.poll();
                int depth = queue.poll();
                if (min <= depth) {
                    continue;
                }
                for (int d = 0; d < di.length; d++) {
                    int nr = row + di[d][0];
                    int nc = col + di[d][1];
                    if (isInRange(nr,nc,n)) {
                        if (nr == n-1 && nc == n-1) {
                            min = min > depth ? depth : min;
                            continue;
                        }
                        int tmp = depth + map[nr][nc] - '0';
                        if (weight[nr][nc] > tmp) {
                            queue.offer(nr);
                            queue.offer(nc);
                            queue.offer(tmp);
                            weight[nr][nc] = tmp;
                        }
                    }
                }
            }
            sb.append(min).append("\n");
        }
        System.out.println(sb);
        sc.close();
    }
     
    private static boolean isInRange(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
}