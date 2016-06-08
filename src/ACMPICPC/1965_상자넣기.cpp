/*
8
1 6 2 5 7 3 5 6
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
vector<int> cache;

int sol()
{
	int maxValue = 0;
	for (int i = 0; i < n; ++i) {
		cache[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i] && cache[j] + 1 > cache[i])
				cache[i] = cache[j] + 1;
		}
		maxValue = max(maxValue, cache[i]);
	}

	return maxValue;
}

int recu(int here)
{
	int& ret = cache[here];
	if (-1 != ret) return ret;

	int maxValue = 1;
	for (int i = here; i < n - 1; ++i) {
		if (arr[here] < arr[i + 1])
			maxValue = max(maxValue, recu(i + 1) + 1);
	}
	ret = maxValue;
	return ret;
}

int main()
{
	cin >> n;
	arr.assign(n, 0);
	cache.assign(n, -1);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	// Àç±Í
	int maxValue = 1;
	for (int i = 0; i < n; ++i)
		maxValue = max(maxValue, recu(i));
	cout << maxValue << endl;

	// ¹Ýº¹¹®
	//cout << sol() << endl;

	return 0;
}