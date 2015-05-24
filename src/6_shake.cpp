#include <iostream>
using namespace std;

int arr[1001];

void shake(int start, int end)
{
	int low, high, cur, count;

	low = start;
	high = end;
	cur = 0;
	count = 0;

	while (low < high) {	// low < high 참이면 반복
		int temp;
		count++;

		/* 아래에서 위로 정렬*/
		for (int i = low; i < high; i++){
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				cur = i;
			}
		}

		// 마지막으로 자리바꿈이 이루어진 위치를 high 변수로 재지정
		high = cur;		

		/* 위에서 아래로 정렬 */
		for (int i = high; i > low; i--){
			if (arr[i - 1] > arr[i]) {
				temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				cur = i;
			}
		}
		// 마지막으로 자리바꿈이 이루어진 위치를 low 변수로 재지정
		low = cur;
	}

	cout << count << endl;

}


int main(void)
{
	int size;
	cin >> size;

	for (int i = 1; i <= size; i++)
		cin >> arr[i];

	shake(1, size);
}
