import java.util.ArrayList;
import java.util.Collections;

class Solution {
	public class Edge implements Comparable<Edge>{
		int start;
		int end;
		int costs;
		
		// ����ġ �������� ����
		@Override
		public int compareTo(Edge V) {
			// TODO Auto-generated method stub
			return costs - V.costs;
		}
		
	}
	public int solution(int n, int[][] costs) {
		int answer = 0;
		int [] visited = new int[101];
		
		// list�� �߰� �� ��ü ����
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
		
		// Edge Ŭ������ comparable �������� �������� ��ü ����
		Collections.sort(list);
		int costsSum = 0;
		for(int i=0;i<list.size();i++) {
			Edge edge = list.get(i);
		
			
			// �� �ʿ� ���� ���
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
