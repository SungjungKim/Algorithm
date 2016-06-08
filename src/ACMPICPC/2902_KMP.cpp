/*
Knuth-Morris-Pratt
*/
#include <iostream>
#include <string>
using namespace std;

string s;

void sol()
{
	cout << s.at(0);
	for (int i = 1; i < s.length(); ++i)
		if (s.at(i) == '-') cout << s.at(i + 1);
	cout << endl;
}

int main()
{
	cin >> s;

	sol();

	return 0;
}