#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int stair[301] = { 0, };
int one[301] = { 0, };
int two[301] = { 0, };

int uStair(int num_stair) {
	int result = 0;

	one[0] = 0, one[1] = stair[1];
	two[0] = 0, two[1] = stair[1];

	for (int i = 2; i <= num_stair; i++) {
		one[i] = MAX(one[i - 2], two[i - 2]) + stair[i];
		two[i] = one[i - 1] + stair[i];
	}
	result = MAX(one[num_stair], two[num_stair]);
	
	return result;
}

int main(void) {
	int num_stair;
	cin >> num_stair;

	for (int i = 1; i <= num_stair; i++)
		cin >> stair[i];

	cout << uStair(num_stair) << endl;
}