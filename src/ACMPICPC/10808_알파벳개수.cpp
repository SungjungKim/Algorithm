#include <iostream>
#include <string>
using namespace std;

string s;
int cnt[26] = { 0, };

void sol()
{
	for (int i = 0; i < s.length(); i++)
		cnt[s.at(i) - 97]++;

	for (int i = 0; i < 26; i++)
		cout << cnt[i] << " ";
	cout << endl;
}

int main()
{
	cin >> s;

	sol();

	return 0;
}