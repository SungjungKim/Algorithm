#include <iostream>
using namespace std;

int main() {
	int arr[7] = { 64, 32, 16, 8, 4, 2, 1 };
	int count = 1;
	int x;
	cin >> x;

	for (int i = 0; i < 7; i++) {
		if (x == arr[i]) {
			cout << count << endl;
			return 0;
		}
		else if (x > arr[i]) {
			for (int j = i + 1; j < 7; j++) {
				if (x > arr[i] + arr[j]) {
					arr[i] = arr[i] + arr[j];
					++count;
				}
				else if (x == arr[i] + arr[j]) {
					cout << ++count << endl;
					return 0;
				}
			}
		}
	}

	return 0;
} 