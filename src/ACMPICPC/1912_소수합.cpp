/*
5
10 -4 3 1 5 
*/
#include <iostream> 
#include <algorithm> 
#include <vector>
using namespace std;

int n;
vector<int> arr;

int sol()
{
	int maxValue = arr[0], cur = arr[0];
	for (int i = 1; i < n; ++i) {
		cur = max(arr[i], cur + arr[i]);
		maxValue = max(maxValue, cur);
	}

	return maxValue;
}

int main()
{
	cin >> n;
	arr.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	long long ans = sol();
	cout << ans << endl;

	return 0;
}