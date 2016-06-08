/*
3 16
*/
#include <stdio.h>

int m, n;

// �ش� ���� �Ҽ��̸� return true;
bool IsPrimeNumber(int num)
{
	if (num == 1) return false;
	// �����ٱ����� �Ǻ��ϵ���(�������� ������ �Ҽ��� �ƴϹǷ�)
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) { // 1�� �ڱ� �ڽ��� ������ ����� ������ ��� false
			return false;
		}
	}

	return true;
}

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; ++i) {
		if (IsPrimeNumber(i)) {
			printf("%d\n", i);
		}
	}

	return 0;
}