import java.util.ArrayList;
import java.util.Collections;

class Solution {
	public class Edge implements Comparable<Edge>{
		int start;
		int end;
		int costs;
		
		// 가중치 기준으로 정렬
		@Override
		public int compareTo(Edge V) {
			// TODO Auto-generated method stub
			return costs - V.costs;
		}
		
	}
	public int solution(int n, int[][] costs) {
		int answer = 0;
		int [] visited = new int[101];
		
		// list에 추가 후 객체 정렬
		ArrayList<Edge> list = new ArrayList<>();

		for (int i = 0; i < costs.length; i++) {
			Edge Edge = new Edge();
			int start = costs[i][0];
			int end = costs[i][1];

			Edge.start = start;
			Edge.end = end;
			Edge.costs = costs[i][2];
			list.add(Edge);
		}
		
		// Edge 클래스의 comparable 기준으로 오름차순 객체 정렬
		Collections.sort(list);
		int costsSum = 0;
		for(int i=0;i<list.size();i++) {
			Edge edge = list.get(i);
		
			
			// 할 필요 없는 경우
			if(visited[edge.start] == 1 && visited[edge.end] == 1) {
				System.out.println("??");
				continue;
			}
			costsSum += edge.costs;
			
			visited[edge.start] = 1;
			visited[edge.end] = 1;
			
			int sum = 0;
			for(int j=0;j<n;j++)
				sum+= visited[j];
			
			if(sum == n)
				break;
			
		}
		
		return costsSum;
	}
}
