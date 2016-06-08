#include <iostream>
using namespace std;

typedef unsigned long long ull;

int getGCD(ull a, ull b)
{
	int r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	int n, gcd;
	ull a, b, lcm;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (a < b) {
			int temp = a;
			a = b;
			b = temp;
		}

		gcd = getGCD(a, b);
		lcm = a / gcd * b;
		cout << lcm << endl;
	}

	return 0;
}