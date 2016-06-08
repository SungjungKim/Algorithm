#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int> > arr;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a > b ? a : b;
}

int sol(int i, int j)
{
	if (i < 1 || j < 1) return 0;
	
	int& ret = cache[i][j];
	if (-1 != ret) return ret;
	ret = 0;

	ret = max(ret, sol(i - 1, j - 1) + arr[i - 1][j - 1]);
	ret = max(ret, sol(i - 1, j) + arr[i - 1][j]);

	return ret;
}

int main()
{
	cin >> n;
	arr.assign(n + 2, vector<int>(n + 2, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> arr[i][j];
	cache.assign(n + 1, vector<int>(n + 1, -1));

	int maxValue = 0;
	for (int i = n; i > 0; --i)
		maxValue = max(maxValue, sol(n, i) + arr[n][i]);
	cout << maxValue << endl;

	return 0;
}