

class Solution {
	public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        answer = n- lost.length;
        
        for(int i=0;i<lost.length;i++) {
        	for(int j=0;j<reserve.length;j++) {
        		if(lost[i] == reserve[j]) {
        			lost[i] = -1;
        			reserve[j] = -1;
        		    answer++;  			
        			break;
        		}
        			
        	}
        }
      
        
        for(int i=0;i<lost.length;i++) {
        	if(lost[i] == -1)
        		continue;
        		
        	for(int j=0;j<reserve.length;j++) {
        		
        		//왼쪽
        		if(lost[i] -1 == reserve[j] && reserve[j] !=-1) {
        			reserve[j] = -1;
        			answer++;
        			break;
        		}
        		//오른쪽
        		else if(lost[i] +1 == reserve[j] && reserve[j] !=-1) {
        			reserve[j] = -1;
        			answer++;
        			break;
        		}
    
        	}
        	
        	
        }
        
        
        return answer;
    }
}
