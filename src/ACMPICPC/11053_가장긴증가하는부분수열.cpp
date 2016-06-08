/*
6
10 20 10 30 20 50
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
vector<int> cache;

int sol(int here)
{
	int& ret = cache[here];
	if (-1 != ret) return ret;

	int maxValue = 1;
	for (int i = here + 1; i < n; ++i)
		if (arr[here] < arr[i])
			maxValue = max(maxValue, sol(i) + 1);

	ret = maxValue;
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	cache.assign(n, -1);
	
	int maxValue = 0;
	for (int i = 0; i < n; ++i) {
		maxValue = max(maxValue, sol(i));
	}
	cout << maxValue << endl;

	return 0;
}