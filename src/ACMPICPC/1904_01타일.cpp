#include <iostream>
#include <vector>
using namespace std;

int length;
vector<int> cache;
const int MOD = 15746;

int recu(int here)
{
	if (length == here) {
		return 1;
	}
	else if (length < here) {
		return 0;
	}
	int& ret = cache[here];
	if (-1 != ret) {
		return ret;
	}

	int sum = 0;
	sum += recu(here + 1) % MOD;
	sum += recu(here + 2) % MOD;
	sum %= MOD;

	ret = sum;
	return sum;
}

int main()
{
	cin >> length;
	cache.assign(length, -1);

	cout << recu(0) << endl;

	return 0;
}