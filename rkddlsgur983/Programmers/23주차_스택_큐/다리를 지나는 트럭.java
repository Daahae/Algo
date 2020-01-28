import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 1, sum = 0, index = 0;
        Queue<Integer[]> queue = new LinkedList<Integer[]>();
        
        Integer[] t = new Integer[] {truck_weights[index], 0};
    	sum += truck_weights[index++];
    	queue.add(t);
    	
    	while (!queue.isEmpty()) {
    		for (Integer[] q: queue) {
    			q[1]++;
    		}
    		if (queue.peek()[1] == bridge_length) {
    			sum -= queue.poll()[0];
    		}
    		
    		if (index < truck_weights.length
    				&& sum + truck_weights[index] <= weight) {
    			t = new Integer[] {truck_weights[index], 0};
    	    	sum += truck_weights[index++];
    	    	queue.add(t);
    		}
    		answer++;
    	}
        return answer;
    }
}