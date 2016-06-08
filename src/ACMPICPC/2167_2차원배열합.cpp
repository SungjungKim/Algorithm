#include <iostream>
using namespace std;

int n, m, k;
int i, j, x, y;
int arr[303][303] = { 0, };
int dir[3][2] = { -1, -1, -1, 0, 0, -1 };

int sol()
{
	int sum = 0;

	for (int a = x; a >= i; a--) {
		for (int b = y; b >= j; b--) {
			sum += arr[a][b];
		}
	}

	return sum;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
		}
	}
	
	cin >> k;
	for (int p = 0; p < k; ++p) {
		cin >> i >> j >> x >> y;
		cout << sol() << endl;
	}

	return 0;
}