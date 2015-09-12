#include <iostream>
using namespace std;

int main(void)
{
	int num_test;
	int x1, y1, r1, x2, y2, r2;
	cin >> num_test;
	for (int x = 1; x <= num_test; x++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		if (!distance) {
			if (r1 == r2) cout << -1 << endl;
			else cout << 0 << endl;
		}
		else if ((r1 + r2) * (r1 + r2) == distance || (r1 - r2) * (r1 - r2) == distance)
			cout << 1 << endl;
		else if ((r1 + r2) * (r1 + r2) < distance || (r1 - r2) * (r1 - r2) > distance)
			cout << 0 << endl;
		else cout << 2 << endl;
	}
}