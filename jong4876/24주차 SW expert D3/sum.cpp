
#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num;
		int adj[102][102];
		int axisRight = 0, axisLeft = 0;
		int maxVal = 0;
		cin >> num;

		for (int i = 1;i <= 100;i++) {
			int colSum = 0;
			for (int j = 1;j <= 100;j++) {
				int tmp;
				cin >> tmp;
				adj[i][j] = tmp;
				colSum += tmp;

				if (i == j)
					axisRight += tmp;

				if (i == (100 - j+1))
					axisLeft += tmp;

			}
			adj[i][101] = colSum;
			maxVal = max(maxVal, colSum);
		}
		maxVal = max(maxVal, axisRight);
		maxVal = max(maxVal, axisLeft);

		for (int i = 1;i <= 100;i++) {
			int rowSum = 0;
			for (int j = 1;j <= 100;j++) {
				rowSum += adj[j][i];
			}
			adj[101][i] = rowSum;
			maxVal = max(maxVal, rowSum);
		}
		cout << "#" << num << " " << maxVal << endl;
	}
	return 0;
}