#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> cache;

ll dp(int n)
{
	if (n == 0) return 0;
	if (n <= 3) return 1;
	if (n <= 5) return 2;
	if (n == 6) return 3;

	ll &ret = cache[n];
	if (-1 != ret) return ret;

	return ret = dp(n - 1) + dp(n - 5);
}

int main()
{
	int test_case, n;
	cin >> test_case;
	cache.assign(101, -1);
	for (int i = 0; i < test_case; ++i) {
		cin >> n;
		cout << dp(n) << endl;
	}

	return 0;
}