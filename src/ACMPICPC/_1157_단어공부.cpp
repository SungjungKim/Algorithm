#include <iostream>
#include <string>
#include <vector>
using namespace std;

string word;
vector<int> cache;

int max(int a, int b)
{
	if (a > b) return a;
	else if (a < b) return b;
	else return -1;
}

// 'A' = 65
// 'a' = 97
int sol(char target, int i)
{
	if (i == word.length() - 1) {
		if (target == word.at(i))
			return 1;
		return 0;
	}

	int idx = (int)target - 97;
	int& ret = cache[idx];
	if (-1 != ret) return ret;
	
	int count = 0;
	if (target == word.at(i)) count = max(count, sol(target, i + 1) + 1);
	else count = max(count, sol(target, i + 1));

	ret = count;
	return count;
}

int main()
{
	cin >> word;
	for (int i = 0; i < word.length(); ++i)
		if (word.at(i) >= 65 && word.at(i) <= 96)
			word.at(i) += 32;

	cache.assign(26, -1);

	int maxValue = 0;
	for (int i = 0; i < word.length(); ++i) {
		maxValue = max(maxValue, sol(word.at(i), i));

		if (maxValue == -1) {
			cout << "?" << endl;
			return 0;
		}
	}
	cout << maxValue << endl;

	return 0;
}