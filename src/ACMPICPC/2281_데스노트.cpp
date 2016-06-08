#include <iostream>
#include <vector>
using namespace std;

int n, m;
int name[1111] = { 0, };
vector<vector<int> > cache;
const int INF = 987654321;

int min(int a, int b)
{
	return a < b ? a : b;
}

int sol(int i, int start)
{
	if (i == n + 1) return 0;

	int& ret = cache[i][start];
	if (ret != -1) return ret; 
	ret = INF;
	
	if (start + name[i] - 1 <= m) {
		ret = min(ret, sol(i + 1, start + name[i] + 1));
	}

	// ´ÙÀ½ ÁÙ
	ret = min(ret, sol(i, 1) + (m - start + 2) * (m - start + 2));
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> name[i];

	cache.assign(1111, vector<int>(1111, -1));

	cout << sol(1, 1) << endl;

	return 0;
}


//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int INF = 987654321;
//int nName, lineWidth;
//int nameLength[1111] = { 0, };
//int cache[1111][1111] = { 0, };
//
//int dfs(int here, int nameCount)
//{
//	int& ret = cache[here][nameCount];
//	if (ret > 0){
//		return ret;
//	}
//	if (nameCount == nName){
//		return 0;
//	}
//
//	ret = INF;
//	if (here + nameLength[nameCount] <= lineWidth){
//		ret = min(ret, dfs(here + nameLength[nameCount] + 1, nameCount + 1));
//	}
//	ret = min(ret, dfs(nameLength[nameCount] + 1, nameCount + 1) + (lineWidth - here + 1) * (lineWidth - here + 1));
//
//	return ret;
//}
//
//int main()
//{
//	cin >> nName >> lineWidth;
//	
//	for (int i = 0; i < nName; ++i){
//		cin >> nameLength[i];
//	}
//
//	cout << dfs(0, 0) << endl;
//
//	return 0;
//}