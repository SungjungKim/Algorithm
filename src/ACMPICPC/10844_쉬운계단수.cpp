#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int n;
const ull MOD = 1000000000;
vector<vector<ull> > cache;

ull sol(int here, int cur)
{
	if (here == n) return 1;

	ull& ret = cache[here][cur];
	if (-1 != ret) return ret;

	ull count = 0;
	if (cur >= 1) count += sol(here + 1, cur - 1) % MOD;
	if (cur <= 8) count += sol(here + 1, cur + 1) % MOD;
	count %= MOD;

	ret = count;
	return count;
}

int main()
{
	cin >> n;
	cache.assign(n + 1, vector<ull>(10, -1));
	ull count = 0;
	for (int i = 1; i <= 9; ++i) {
		count += sol(1, i);
		count %= MOD;
	}

	cout << count << endl;

	return 0;
}