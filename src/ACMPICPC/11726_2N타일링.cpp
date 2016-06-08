#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;
vector<int> cache;

int sol(int n)
{
	if (n <= 2) return n;
	else {
		int& ret = cache[n];
		if (-1 != ret) return ret;
		ret = 0;

		return ret = (sol(n - 1) + sol(n - 2)) % MOD;
	}
}

int main()
{
	int n;
	cin >> n;
	cache.assign(1001, -1);

	cout << sol(n) << endl;

	return 0;
}