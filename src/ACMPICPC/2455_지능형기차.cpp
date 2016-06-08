#include <iostream>
using namespace std;

int arr[12][2] = { 0, };

int max(int a, int b)
{
	return a > b ? a : b;
}

int sol()
{
	int maxValue = 0;
	for (int i = 1; i < 11; ++i) {
		arr[i][1] += arr[i - 1][1] - arr[i][0];
		maxValue = max(maxValue, arr[i][1]);	
	}

	return maxValue;
}

int main()
{
	for (int i = 1; i < 11; i++) 
		for (int j = 0; j < 2; j++) 
			cin >> arr[i][j];
	cout << sol() << endl;
	
	return 0;
}