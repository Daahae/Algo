
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int visited[21][21];
map<int, int> maps;
int direction; // 우하-2 좌하-1 좌상1 우상2
int N;
int start;
int startX, startY;


bool isInArr(int x, int y) {
	if ((x>=1 && x <= N) && (y>=1 && y <= N))
		return true;

	return false;
}

bool isDuplicateDesert(int cnt) {
	if (maps.size() == cnt)
		return true;

	return false;

}
void dfs(int adj[21][21], int x, int y, int direction, int cnt) {

	cnt++;

	if (!isInArr(x,y)) {
		cout << "루트 없음" << endl;
		maps.clear();
		return;
	}
		

	// 디저트 코스를 중복없이 저장하기 위한 map
	maps.insert(make_pair(adj[x][y], cnt)); // 디저트종류, 순서 pair
	cout << x << "," << y << " dir : " <<direction<< endl;
	
	// 디저트 코스가 중복된 경우
	if (!isDuplicateDesert(cnt)) {

		if (direction == 2 && startX == x && startY == y) {
			cout << "코스 성공" << endl;
			return;
		}

		cout << "코스 중복" << endl;
		maps.clear();
		return;
	}

	// 우하
	if (direction == -2) {
		if (isInArr(x + 1, y + 1))
			dfs(adj, x + 1, y + 1, -2, cnt);

		else {
			dfs(adj, x + 1, y - 1, -1, cnt);
		}
	}

	// 좌하
	if (direction == -1) {
		if (isInArr(x + 1, y - 1))
			dfs(adj, x + 1, y - 1, -1, cnt);

		else {
			dfs(adj, x - 1, y - 1,  1, cnt);
		}
	}

	// 좌상
	if (direction == 1) {
		if (isInArr(x - 1, y - 1))
			dfs(adj, x - 1, y - 1, 1, cnt);

		else {
			dfs(adj, x - 1, y + 1, 2, cnt);
		}
	}

	// 우상
	if (direction == 2) {
		if (isInArr(x - 1, y + 1))
			dfs(adj, x - 1, y + 1, 2, cnt);

		else {
		
			// 출발지와 도착지가 다를 때 - 수정 필요
			if (adj[x][y] != start) {
				cout << "??" << endl;
				maps.clear();
				return;
			}
			cout << "dest" << endl;
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

		int adj[21][21];
		int maxVal = -1;
		cin >> N;

		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				int tmp;
				cin >> tmp;
				adj[i][j] = tmp;
			}
		}
		
		// 나올 수 있는 최대 길이는 (N-1) + (N-1)
		for (int i = 1;i <= N-1;i++) {
			for (int j = 1;j <= N-1;j++) {
				cout << "start :" << i << " " << j << endl;
				startX = i;
				startY = j;

				// 현재 인덱스를 출발지로 하여 나올수 있는 경우 계산
				start = adj[i][j];
				dfs(adj, i, j,-2,0);
				int size = maps.size();
				
				// 투어를 완성할 수 없는 경우
				if (size == 0)
					size = -1;

				maxVal = max(maxVal, size);
				maps.clear();
			}
		}
		cout << "#" << test_case << " " << maxVal<<endl;

	}
	return 0;
}