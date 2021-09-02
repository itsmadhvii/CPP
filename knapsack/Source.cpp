#include <iostream>
#include <vector>

using namespace std;

int knapsack(int c, int v[], int w[], int n) {
	vector<vector<int>> K(n + 1, vector<int>(c + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= c; j++) {
			if (i == 0 or j == 0) K[i][j] = 0;
			else if (w[i - 1] <= j) {
				K[i][j] = max(K[i - 1][j], K[i - 1][j - w[i - 1]] + v[i - 1]);
			}
			else K[i][j] = K[i - 1][j];
		}
	}
	return K[n][c];
}

int main() {
	int v[] = { 60, 100, 120 };
	int w[] = { 10,20,30};
	int c = 50;
	int n = sizeof(v) / sizeof(v[0]);
	cout << knapsack(c, v, w, n);
	return 0;
}