#include <iostream>
#include <vector>
using namespace std;

int n, k;
const int INF = 987654321;
vector<int> coin;
vector<vector<int> > cache;

int min(int a, int b)
{
	return a > b ? b : a;
}

int sol(int i, int sum)
{
	if (i > n) return INF;
	if (sum > k) return INF;
	if (i == n) {
		if (sum == k) return 0;
		return INF;
	}

	int& ret = cache[i][sum];
	if (-1 != ret) return ret;
	ret = INF;
	
	ret = min(ret, sol(i + 1, sum));
	ret = min(ret, sol(i, sum + coin[i]) + 1);

	return ret;
}

int main()
{
	cin >> n >> k;
	coin.assign(n + 1, 0);
	for (int i = 0; i < n; ++i)
		cin >> coin[i];
	cache.assign(n + 1, vector<int>(k + 1, -1));

	cout << sol(0, 0) << endl;

	return 0;
}