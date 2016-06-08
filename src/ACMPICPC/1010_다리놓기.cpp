#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > cache;
int n, m;

// nCr = n-1Cr-1 + n-1Cr
int rec(int w, int e)
{
	if (w == e || e == 0) return 1;
	else {
		int &ret = cache[w][e];
		if (-1 != ret) return ret;
		return ret = rec(w - 1, e - 1) + rec(w - 1, e);
	}
}

int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; ++i) {
		cache.assign(30, vector<int>(30, -1));
		cin >> n >> m;
		cout << rec(m, n) << endl;
	}

	return 0;
}
