class Solution {
    public int solution(String arrangement) {
        int answer = 0;
        int cnt = 0;
        for (int i = 0; i < arrangement.length(); i++) {
        	if (arrangement.charAt(i) == '(') {
        		if (arrangement.charAt(i+1) == ')') {
            		answer += cnt;
            		i++;
        		} else {
        			cnt++;
        		}
        	} else {
        		cnt--;
        		answer++;
        	}
        }
        return answer;
    }
}