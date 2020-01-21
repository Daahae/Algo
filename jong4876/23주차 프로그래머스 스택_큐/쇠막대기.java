import java.util.Stack;
import java.util.Vector;

class Solution {
    public int solution(String arrangement) {
        Stack<Character> s = new Stack<>();
    	int answer = 0;
    	
    	// cut by C
    	arrangement = arrangement.replace("()", "C");
    	
    	//()(((CC)(C)C))(C)
    	for(int i=0;i<arrangement.length();i++) {
    		if(arrangement.charAt(i) == '(')
    			s.push('(');
    		
    		else if(arrangement.charAt(i) == 'C') {
    			System.out.println(s.size());
    			answer+= s.size();
    		}else { 
    			s.pop();
    			answer++;
    		}
    	}
        
        
        return answer;
    }
}