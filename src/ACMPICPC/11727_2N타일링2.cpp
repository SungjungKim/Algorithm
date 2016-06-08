#include <iostream>
#include <vector>
using namespace std;

const int mod = 10007;
vector<int> cache;

int sol(int n)
{
	if (n <= 1) return n;
	else if (n == 2) return 3;
	else {
		int& ret = cache[n];
		if (-1 != ret) return ret % mod;
		return ret = (sol(n - 1) + 2 * sol(n - 2)) % mod;
	}
}

int main()
{
	int n;
	cin >> n;
	cache.assign(1003, -1);

	cout << sol(n) << endl;

	return 0;
}