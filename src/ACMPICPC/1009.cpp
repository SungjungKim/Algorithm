#include <iostream>
using namespace std;

int arr[10] = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int process(int a, int b) {
	int tmp;

	if (b == 1) {	// base case
		return a;
	}
	else if (b % 2 == 1) {	// b > 1 && È¦¼ö
		tmp = process(a, (b - 1) / 2) % 10;
		return (a * tmp * tmp) % 10;
	}
	else {	// b > 1 && Â¦¼ö
		tmp = process(a, b / 2) % 10;
		return (tmp * tmp) % 10;
	}
}

int main(void) {
	
	int num_data;
	int a, b;
	cin >> num_data;
	for (int i = 0; i < num_data; i++) {
		cin >> a >> b;
		cout << arr[process(a, b)] << endl;
	}

	return 0;
}