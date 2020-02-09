import java.util.Scanner;
 
public class Solution {
    
	private static int length;
	
    public static void main(String[] args) {
         
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            sb.append("#").append(i).append(" ");
            int n = sc.nextInt();
            int m = sc.nextInt();
            boolean[][] node = new boolean[n+1][n+1];
            for (int j = 0; j < m; j++) {
            	int x = sc.nextInt();
            	int y = sc.nextInt();
            	node[x][y] = true;
            	node[y][x] = true;
            }
            
            length = 1;
            boolean[] visit = new boolean[n+1];
            for (int j = 1; j <= n; j++) {
            	visit[j] = true;
            	dfs(1, j, node, visit);
            	visit[j] = false;
            }
            sb.append(length).append("\n");
        }
        System.out.println(sb);
        sc.close();
    }
    
    private static void dfs(int depth, int start, boolean[][] node, boolean[] visit) {
    	
    	for (int i = 1; i < node.length; i++) {
    		if (node[start][i] && !visit[i]) {
    			visit[i] = true;
    			length = length < depth+1 ? depth+1 : length;
    			dfs(depth+1, i, node, visit);
    			visit[i] = false;
    		}
    	}
    }
}