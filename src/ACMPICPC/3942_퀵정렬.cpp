#include <iostream>
#include <stdlib.h>
using namespace std;

int n;
int arr[51];

int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	qsort(arr, n, sizeof(int), compare);
	cout << arr[0] * arr[n - 1] << endl;

	return 0;
}

