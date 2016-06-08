#include <iostream>
#include <vector>
using namespace std;

int arr[5][4] = { 0, };

int main()
{
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 4; ++j){
			cin >> arr[i][j];
		}
		for (int j = 0; j < 3; ++j) {
			arr[i][j + 1] += arr[i][j];

		}
	}

	int maxValue = 0;
	int idx = 0;
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 4; ++j) {
			if (arr[i][j] > maxValue) {
				maxValue = arr[i][j];
				idx = i;
			}
		}
	}

	cout << idx + 1 << " " << maxValue << endl;

	return 0;
}
