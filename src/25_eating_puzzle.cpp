#include <iostream>
using namespace std;

int arr[35000] = {0, };
int total = 0;

void process(int c, int b, int currentSum, int count)
{
	int temp;
	if(total < currentSum) total = currentSum;

	/* 종료 조건 */
	if(count == b) return;

	/* update */
	temp = currentSum + arr[count];

	process(c, b, temp, count + 1);	
	// 한도를 초과하지 않았다면
	if(c > temp)
		process(c, b, temp, count + 1);
}


int main()
{
	int c, b, max = 0;
	cin >> c >> b;
	
	for(int i = 0; i < b; i++)
		cin >> arr[i];

	cout << total << endl;

	return 0;
}
