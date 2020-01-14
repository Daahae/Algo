class Solution {
    public int solution(String name) {
        int answer = 0;
        int answerRight = 0;
        int answerLeft = 0;
        int flag =0;
        for(int j=0;j<name.length();j++) {
        	if(name.charAt(j) != 'A') {
        		flag =1;
        		break;
        	}
        }
        if(flag == 0) // all A
        	return 0;
        
        int i;
        for(i=0;i<name.length();i++) {
        	
        	int upCharGap = (int)name.charAt(i) - (int)'A';
        	int downCharGap = 26 - upCharGap;
        	downCharGap = Math.abs(downCharGap);
            
        	//System.out.println(upCharGap+ " : "+ downCharGap);
        	
        	answerRight += Math.min(upCharGap, downCharGap);
        	
            answerRight++;
        }
        answerRight--;
        if(name.charAt(i-1) == 'A')
        	answerRight--;
        
        for(i=name.length();i>0 ;i--) {
        	
        	int upCharGap = (int)name.charAt(i%name.length()) - (int)'A';
        	int downCharGap = 26 - upCharGap;
        	downCharGap = Math.abs(downCharGap);
            
        	System.out.println(upCharGap+ " : "+ downCharGap);
        	
        	answerLeft += Math.min(upCharGap, downCharGap);
            answerLeft++;
        }
        answerLeft--;
        if(name.charAt(i+1) == 'A')
        	answerLeft--;
        
        answer = Math.min(answerRight, answerLeft);
        return answer;
    }
}
