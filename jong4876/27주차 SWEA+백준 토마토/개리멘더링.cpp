#include<iostream>
#include<algorithm>

using namespace std;
int N;
int city[11];
int adj[11][11];
int visited[11];
int flag = 0;
int cnt = 0;
int redSum = 0, blueSum = 0;
int minDiff = 101;


void init() {
	flag = 0;
	cnt = 0;
	redSum = 0, blueSum = 0;

	for (int j = 1;j <= N;j++) {
		visited[j] = 0;
	}
}

bool isInArr(int x, int y) {

	if (x<1 || x>N)
		return false;

	if (y<1 || y>N)
		return false;

	return true;
}

// visited 빨강 :-1, 파랑 : 1 -> color에 맞는 길만 DFS
void DFS(int start, int color) {

	visited[start] = 0;

	if (color == -1)
		redSum += city[start];

	if (color == 1)
		blueSum += city[start];

	for (int i = 1;i <= N;i++) {
		// 길이 있고 색깔이 같으면 이동
		if(adj[start][i] == 1 && visited[i] == color)
			DFS(i, color);
	}
}

int main() {

	cin >> N;

	for (int i = 1;i <= N;i++) {
		int num;
		cin >> num;
		city[i] = num;
	}
	
	for (int i = 1;i <= N;i++) {
		int adjNum;
		int vertex;
		cin >> adjNum;
		for (int j = 0;j < adjNum;j++) {
			cin >> vertex;
			adj[i][vertex] = 1;
			adj[vertex][i] = 1;
		}
	}

	//1 12 123 1234 12345  2 23 234 2345 ~  13 은?
	for (int i = 1;i <= N;i++) {
		for (int k = i;k <= N;k++) {

			init();
			int blueIdx = 0;

			// 빨강으로 색칠 ** i~k
			for (int j = i;j <= k;j++) 
				visited[j] = -1;
			
			// 빨강의 나머지를 파랑으로
			for (int j = 1;j <= N;j++) {
				if (visited[j] == 0) {
					visited[j] = 1;
					blueIdx = j;
				}
			}

			// 색깔별 DFS
			DFS(i, -1);
			DFS(blueIdx, 1);

			for (int j = 1;j <= N;j++) {
				if (visited[j] != 0)
					flag = 1;
			}

			cout << "redSum : " << redSum << "  blueSum : " << blueSum << " flag : " << flag << endl;

			// 모두 방문 가능하면
			if (flag == 0) {
				int diff = abs(blueSum - redSum);
				if (minDiff > diff) 
					minDiff = diff;	
			}
		}
		
	}

	if (minDiff == 101)
		cout << -1;

	else
		cout << minDiff;
	

	return 0;
}