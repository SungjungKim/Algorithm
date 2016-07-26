#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> letters;

void generate(int index, int length) {
    if (length == 4) return;

    printf("%c", letters[index]);
    if (letters[index] < letters[
}

int main() {
    int L, C;
    scanf("%d %d", &L, &C);
    letters.assign(C, '\0');
    for (int i = 0; i < letters.size(); ++i)
	cin >> letters[i];

    sort(letters.begin(), letters.end());

    for (int i = 0; i < letters.size() - 3; ++i) {
	generate(i, 1);
	printf("\n");
    }
    
    return 0;
}

