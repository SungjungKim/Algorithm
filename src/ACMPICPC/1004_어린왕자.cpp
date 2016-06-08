#include <iostream>
using namespace std;

struct circle{
	int x;
	int y;
	int r;

};

int startX, startY, finishX, finishY, numOfCircle;
circle* cir;

int square(int num) {
	return num * num;
}

int checkDistance(int startX, int startY, int finishX, int finishY, circle* cir, int size) { 
	int count = 0;
	bool inStart = false;
	bool inFinish = false;
	// check whether the start point is in a circle
	// 1. find the distance between the start point (finish point) and the center in the circle
	// 2. check whether two point(start, finish) are in the same circle
	// 3. increase count if either start or finish point is in the circle.

	for (int i = 0; i < size; i++){
		inStart = false;
		inFinish = false;

		if (square(cir[i].r) > square(startX - cir[i].x) + square(startY - cir[i].y)) inStart = true;
		if (square(cir[i].r) > square(finishX - cir[i].x) + square(finishY - cir[i].y)) inFinish = true;

		if (inStart && !inFinish) count++;
		else if (!inStart && inFinish) count++;
	}

	return count;
}

int main(){
	int num_testCase;
	cin >> num_testCase;
	while (num_testCase-- > 0) {
		cin >> startX >> startY >> finishX >> finishY >> numOfCircle;
		cir = new circle[numOfCircle]();

		for (int i = 0; i < numOfCircle; i++)
			cin >> cir[i].x >> cir[i].y >> cir[i].r;

		cout << checkDistance(startX, startY, finishX, finishY, cir, numOfCircle) << endl;
	}
}