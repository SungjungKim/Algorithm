#include <iostream>
using namespace std;

class Building {
private:
	int time;
	int val;
	Building *build[1001];
	int num_build;
public:
	Building();
	Building(int time);
	int getVal();
	void addBuild(Building* building);
};

Building::Building() {}

Building::Building(int time) {
	this->val = -1;
	this->time = time;
	this->num_build = 0;
}

int Building::getVal() {
	if (val != -1) return val;

	int max = 0;
	for (int i = 0; i < num_build; i++){
		int tmp = build[i]->getVal();
		if (tmp > max) max = tmp;
	}
	val = max + time;

	return val;
}

void Building::addBuild(Building* building) {
	build[num_build++] = building;
}

int main() {
	int num_testCase;
	cin >> num_testCase;

	while (num_testCase--) {
		int n, k;
		cin >> n >> k;

		Building* arr = new Building[n];

		for (int i = 0; i < n; i++){
			int time;
			cin >> time;
			arr[i] = Building(time);
		}

		for (int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			arr[y - 1].addBuild(&arr[x - 1]);
		}

		int w;
		cin >> w;

		cout << arr[w - 1].getVal() << endl;

		delete[] arr;
	}

	return 0;
}