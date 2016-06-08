/*
3 16
*/
#include <stdio.h>

int m, n;

// 해당 수가 소수이면 return true;
bool IsPrimeNumber(int num)
{
	if (num == 1) return false;
	// 제곱근까지만 판별하도록(제곱수는 어차피 소수가 아니므로)
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) { // 1과 자기 자신을 제외한 약수가 존재할 경우 false
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