/*
20 30 10
*/
#include <iostream>
using namespace std;

inline int mid(int a, int b, int c)
{
	if (a > b) {
		if (b > c) return b;
		// c > b
		if (a > c) return c;
		else return a;
	}
	else { // b > a
		if (a > c) return a;
		// c > a
		if (b > c) return c;
		else return b;
	}
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	cout << mid(a, b, c) << endl;

	return 0;
}