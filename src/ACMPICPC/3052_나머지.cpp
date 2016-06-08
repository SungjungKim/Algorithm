#include <iostream>
using namespace std;

int base[42] = { 0, };
int arr[10] = { 0, };

int main()
{
	int num;
	for (int i = 0; i < 10; ++i)  {
		cin >> num;
		base[num % 42]++;
	}	

	int ans = 0;
	for (int i = 0; i < 42; ++i)
		if (base[i] != 0)
			ans++;
	cout << ans << endl;

	return 0;
}