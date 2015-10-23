#include <iostream>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int a[50] = { 0, };
int b[50] = { 0, };
int result[50][2] = { 0, };

int index_max, index_min;

void init(int num_data) {
	for (int i = 0; i < num_data; i++)
		cin >> a[i];
	for (int i = 0; i < num_data; i++)
		cin >> b[i];
}

int findMin(int num_data, int left, int right) {

	int half;

	if (left == right) {
		index_min = left;
		return a[left];
	}
	else {
		half = (left + right) / 2;
		return MIN(findMin(num_data, left, half), findMin(num_data, half + 1, right));
	}
}

int findMax(int num_data, int left, int right) {

	int half;

	if (left == right) {
		index_max = left;
		return b[left];
	}
	else {
		half = (left + right) / 2;
		return MAX(findMax(num_data, left, half), findMax(num_data, half + 1, right));
	}
}

void sort(int num_data) {

	for (int i = 0; i < num_data; i++) {
		result[i][0] = findMax(num_data, 0, num_data - 1);
		result[i][1] = findMin(num_data, 0, num_data - 1);

		b[index_max] = 0;
		a[index_min] = 9999;
	}
}

int calc(int num_data) {

	int s = 0;
	for (int i = 0; i < num_data; i++){
		s += result[i][0] * result[i][1];
	}
	
	return s;
}

int main(void) {
	
	int num_data;
	cin >> num_data;

	init(num_data);
	sort(num_data);
	cout << calc(num_data) << endl;

	return 0;
}