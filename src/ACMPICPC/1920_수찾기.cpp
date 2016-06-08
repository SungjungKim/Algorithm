#include <iostream>
#include <cstdlib>
using namespace std;

int n, m;
int a[10001], b[10001];

//int compare(const void *a, const void *b)
//{
//	return (*(int*)a - *(int*)b);
//}

void sort()
{
	int tmp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

// return index
int find(int left, int right, int value)
{
	// cond
	if (left > right) return 0;
	else {
		int mid = (left + right) / 2;

		// go
		if (a[mid] == value)
			return 1;
		else if (a[mid] > value)
			return find(left, mid - 1, value);
		else
			return find(mid + 1, right, value);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	//qsort(a, n, sizeof(int), compare);
	sort();

	for (int i = 0; i < m; ++i) {
		cout << find(0, m - 1, b[i]) << endl;
	}

	return 0;
}