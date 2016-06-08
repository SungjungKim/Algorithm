#include <iostream>
#include <vector>
using namespace std;

int n, k;
const int MOD = 1000000003;
vector<vector<vector<int> > > cache;

int sol(int i, int selected, int first)
{
	if (selected == k) return 1;
	if (i >= n) return 0;

	int& ret = cache[i][selected][first];
	if (ret != -1) return ret;
	ret = 0;

	if (i == n - 1) {	
		if (first == 1) return 0;

		ret = (sol(i + 2, selected + 1, first) + sol(i + 1, selected, first)) % MOD;
		return ret;
	}
	
	// i번째 선택하는 경우
	if (i == 0) ret = (ret + sol(i + 2, selected + 1, 1)) % MOD;
	else ret = (ret + sol(i + 2, selected + 1, first)) % MOD;

	// i번째 선택 안하는 경우
	if (i == 0) ret = (ret + sol(i + 1, selected, 0)) % MOD;
	else ret = (ret + sol(i + 1, selected, first)) % MOD;

	return ret;
}

int main()
{
	cin >> n >> k;
	
	cache.assign(1003, vector<vector<int> >(1003, vector<int>(2, -1)));
	
	cout << sol(0, 0, 0) << endl;

	return 0;
}