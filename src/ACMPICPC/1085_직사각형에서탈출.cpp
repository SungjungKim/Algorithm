#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int min1, min2;
	min1 = min(x, y);
	min2 = min(w - x, h - y);
	cout << min(min1, min2) << endl;
		
	return 0;
}