/*
4 2
1 1 1 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;

int sol()
{
	int count = 0;
	long long sum = arr[0], cur = arr[0];
	for (int i = 1; i < n; ++i) {
		sum = cur + arr[i];
		if (sum == m) {
			count++;
			sum = arr[i];
			cur = arr[i];
		}
	}
	return count;
}

int main()
{
	int num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	cout << sol() << endl;

	return 0;
}