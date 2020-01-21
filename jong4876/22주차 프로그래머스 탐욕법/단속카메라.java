import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        
        Arrays.sort(routes, new Comparator<int[]>(){

			@Override
			public int compare(int[] o1, int[] o2) {
				
				return o1[1] - o2[1];
			}     	
        });
        int left =routes[0][0];
        int right = routes[0][1];
        
        
        for(int i=1;i<routes.length;i++) {
        	
        	// ���� ����������
			if (left <= routes[i][0] &&right >= routes[i][1]) {
				left = routes[i][0];
				right = routes[i][1];  	
			}

			else if (left <= routes[i][1] && routes[i][1] <=right)
				right = routes[i][1];  		
			
			else if(right >= routes[i][0] && routes[i][0] >=left)
				left = routes[i][0];
        
			// ������ �� �����ٸ� ���� �� ī��Ʈ
        	else {
        		answer++;
        		left = routes[i][0];
        		right = routes[i][1];
        	}
        	System.out.println(left + " : "+right);
        	
        }
        
        
        
        
        
        
        return answer+1;
    }
}