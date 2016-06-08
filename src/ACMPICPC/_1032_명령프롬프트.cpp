/*
3
config.sys
config.inf
configures
*/
#include <iostream>
#include <string>
using namespace std;

int n;
string s[100];

void sol()
{
	for (int j = 0; j < s[0].length(); ++j) {
		int count = 1;
		for (int i = 0; i < n - 1; ++i) {
			count++;
			if (count == n) {
				if (s[i].at(j) == s[i + 1].at(j))
					cout << s[i].at(j);
				else cout << "?";
				break;
			}
		}
	}
	cout << endl;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	if (n == 1) cout << s[0] << endl;
	else sol();

	return 0;
}