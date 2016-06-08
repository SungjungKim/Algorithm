/*
5 0
-7 -3 -2 5 8
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, s;
vector<int> arr;

int sol(int here)
{
	
}


int main()
{
	cin >> n >> s;
	arr.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int count = 0;
	for (int i = 0; i < n; ++i) {
		count += sol(i);
		if (s == arr[i]) 
			count++;
	}

	cout << count << endl;

	return 0;
}