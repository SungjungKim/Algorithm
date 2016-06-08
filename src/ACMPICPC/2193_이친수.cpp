#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int n;
vector<vector<ll> > cache;

// i번째에 이전 자리가 c일 때
ll rec(int i, int c)
{
	if (i == n) {
		if (c == 0) {	// 마지막 전 자리가 0인 경우, 01, 02 가능
			return 2;
		}
		else if (c == 1) {	// 마지막 전 자리가 1인 경우, 10만 가능
			return 1;
		}
	}

	ll &ret = cache[i][c];
	if (-1 != ret) return ret;

	if (c == 0) {	// 현재 자리 숫자가 0인 경우
		ret = rec(i + 1, 0) + rec(i + 1, 1);
	}
	else {	// 현재 자리 숫자가 1인 경우
		ret = rec(i + 1, 0);
	}

	return ret;
}

int main()
{
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	cache.assign(90, vector<ll>(90, -1));

	cout << rec(2, 1) << endl;

	return 0;
}