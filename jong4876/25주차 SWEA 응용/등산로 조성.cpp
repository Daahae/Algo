#include<algorithm>
#include<iostream>

using namespace std;
int maxRouteCnt = 0;
int N;
int visited[10][10];
int maxHeight, minHeight;
int localMaxRouteCnt = 0;
int downCnt = 1;

bool isMoveNext(int x, int y) {
	if ((x >= 1 && x <= N) && (y >= 1 && y <= N)) {
		if (visited[x][y] == 0)
			return true;

		else
			false;
	}

	return false;
}


//어디든지 움직일 수 있는지
bool isMoveAnyway(int x, int y) {
	if (isMoveNext(x - 1, y) || isMoveNext(x + 1, y) || isMoveNext(x, y - 1) || isMoveNext(x, y + 1))
		return true;

	return false;
}


void dfs(int map[10][10], int x, int y, int K, int routeCnt) {

	int flag = 0;
	visited[x][y] = 1;
	cout << x<<" , " <<y<<endl;

	if (!isMoveAnyway(x, y)) {
		localMaxRouteCnt = max(routeCnt, localMaxRouteCnt);
		cout << "localCnt : " << localMaxRouteCnt << endl;
		return;
	}

	//동쪽
	if (isMoveNext(x, y + 1) && (map[x][y]-downCnt) == map[x][y+1]) {
		flag = 1;
		downCnt = 1;

		dfs(map, x, y + 1, K, routeCnt+1);
		visited[x][y + 1] = 0; 
	}
	//서쪽
	if (isMoveNext(x, y - 1) && (map[x][y] - downCnt) == map[x][y-1]) {
		flag = 1;
		downCnt = 1;

		dfs(map, x, y - 1, K, routeCnt+1);
		visited[x][y - 1] = 0;
	
	}
	//북쪽
	if (isMoveNext(x-1, y) && (map[x][y] - downCnt)  == map[x-1][y]) {
		flag = 1;
		downCnt = 1;

		dfs(map, x - 1, y, K, routeCnt+1);
		visited[x - 1][y] = 0;
	}
	//남쪽
	if (isMoveNext(x+1, y) && (map[x][y] - downCnt) == map[x+1][y]) {
		flag = 1;
		downCnt = 1;

		dfs(map, x + 1, y, K, routeCnt+1);
		visited[x + 1][y] = 0;
	
	}

	// -1값이 없다면 더큰 간격으로 down or 산깎기
	if (flag == 0 && K>0) {
		cout << "?? : "<<map[x][y] << endl;
		//동쪽
		if (isMoveNext(x, y + 1) && ((map[x][y]-downCnt) == map[x][y + 1] - K)) {
			map[x][y + 1] -= K;
			downCnt = 1;
			dfs(map, x, y+1, 0, routeCnt);
		}
		//서쪽
		if (isMoveNext(x, y - 1) && ((map[x][y]-downCnt) == map[x][y - 1] - K)) {
			map[x][y - 1] -= K;
			downCnt = 1;
			dfs(map, x, y - 1, 0, routeCnt);
		}
		//북쪽
		if (isMoveNext(x - 1, y) && ((map[x][y]-downCnt) == map[x - 1][y]-K)){
			map[x-1][y] -= K;
			downCnt = 1;
			dfs(map, x-1, y, 0, routeCnt);
		}
		//남쪽
		if (isMoveNext(x + 1, y) && ((map[x][y]-downCnt) == map[x + 1][y]-K)) {
			map[x+1][y] -= K;
			downCnt = 1;
			dfs(map, x+1, y, 0, routeCnt);
		}

	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int map[10][10];
		int K;
		minHeight = 99999;
		maxHeight = -1;
		maxRouteCnt = 0;

		cin >> N >> K;
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				int tmp;
				cin >> tmp;
				map[i][j] = tmp;
				visited[i][j] = 0;

				if (tmp < minHeight)
					minHeight = tmp;

				if (tmp > maxHeight)
					maxHeight = tmp;
			}
		}

		// 1씩빼는길로 가는데, 1이 안빠지면 K써서 빼기
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {

				// 각 출발지에서의 최댓값
				localMaxRouteCnt = 0;
				
				// 한계단씩 내려가기 위한 장치
				downCnt = 1;

				// i,j에서 시작
				if (map[i][j] == maxHeight) {
					cout << "start "<<endl;
					dfs(map, i, j, K,1);
					maxRouteCnt = max(localMaxRouteCnt, maxRouteCnt);
				}
				
			}
		}
		cout << "#" << test_case << " " << maxRouteCnt << endl;

	}
	return 0;
}