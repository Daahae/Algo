import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public static int[] solution(int[] progresses, int[] speeds) {
        
    	Queue<Integer> q = new LinkedList<>();
    	List<Integer> answerList = new ArrayList<>();
    	for (int i = 0; i < progresses.length; i++) {
    		int release = (int) Math.ceil((100-progresses[i]) / (double)speeds[i]);
    		if (!q.isEmpty() && q.peek() < release) {
    			answerList.add(q.size());
    			q.clear();
    		}
			q.add(release);
    	}
    	answerList.add(q.size());
    	
    	int[] answer = new int[answerList.size()];
    	for (int i = 0; i < answer.length; i++) {
    		answer[i] = answerList.get(i);
    	}
        return answer;
    }
}