import java.util.Scanner;
 
public class Solution {
 
    static final int n = 8;
     
    public static void main(String[] args) {
         
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= 10; i++) {
            sb.append("#").append(i).append(" ");
            int len = sc.nextInt();
            char[][] map = new char[n][n];
            for (int j = 0; j < n; j++) {
                map[j] = sc.next().toCharArray();
            }
             
            int ans = 0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n-len+1; k++) {
                    int row = 0, col = 0;
                    for (int l = 0; l < len/2; l++) {
                        if (map[j][k+l] == map[j][k+len-1-l]) {
                            row++;
                        }
                        if (map[k+l][j] == map[k+len-1-l][j]) {
                            col++;
                        }
                    }
                    if (row == len/2) ans++;
                    if (col == len/2) ans++;
                }
            }
            sb.append(ans).append("\n");
        }
        System.out.println(sb);
        sc.close();
    }
     
    static boolean isValid(int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
}