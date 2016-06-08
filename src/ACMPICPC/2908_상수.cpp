#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int n1[11111], n2[11111];

int tmp(int i)
{
	if (i == 0) return 1;

	int va = 1;
	for (int k = 1; k < i; k++) va *= 10;
	return va;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int sol()
{
	int num1 = 0, num2 = 0;
	for (int i = 0; i < s1.length(); ++i) {
		n1[i] = (s1.at(s1.length() - 1 - i) - 48) * tmp(s1.length() - i);
		num1 += n1[i];
	}
	for (int i = 0; i < s2.length(); ++i) {
		n2[i] = (s2.at(s2.length() - 1 - i) - 48) * tmp(s2.length() - i);
		num2 += n2[i];
	}

	return max(num1, num2);
}

int main()
{
	cin >> s1 >> s2;
	
	cout << sol() << endl;

	return 0;
}