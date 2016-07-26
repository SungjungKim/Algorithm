// 5
// 6 3 2 10 -10
// 8
// 10 9 -5 2 3 4 5 -10
#include <iostream>
#include <map>
using namespace std;

int N, M, card;
map<int, int> m;

void init() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> card;
        m[card] = 1;
    }
}

void check() {
    for (int i = 0; i < m.size(); ++i) {
        
    }
}

int main() {
    init();

    check();

	return 0;
}
