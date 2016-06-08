#include <iostream>
#include <string>
using namespace std;

string hexa;

int convert()
{
	int ret = 0;
	for (int i = 0; i < hexa.length(); ++i) {
		ret *= 16;
		char ch = hexa[i];
		if (ch >= '0' && ch <= '9') 
			ret += (ch - '0');
		else
			ret += (ch - 'A') + 10;
	}

	return ret;
}

int main()
{
	cin >> hexa;

	cout << convert() << endl;

	return 0;
}
