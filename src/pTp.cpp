/*
���츮�� �������� �� ����� ����Ѵ�. �� ����� �׸��� ���� �¿� ��Ī�̴�.


�Է�
�Է��� 20 ������ �ڿ����̴�.

���
��� ���� �������� ����Ѵ�.

����� ��
�Է�
1

���
1

�Է�
2

���
121

�Է�
3

���
1213121

�Է�
4

���
121312141213121

�Է�
5

���
1213121412131215121312141213121
*/
#include <iostream>
using namespace std;

void process(int height) {
	if (height == 1) {
		cout << height;
		return;
	}

	process(height - 1);
	cout << height;
	process(height - 1);
}


int main(void) {
	int height;
	cin >> height;

	process(height);
}