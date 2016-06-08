/*
The Curious Case of Benjamin Button
01234
*/
#include <iostream>
#include <string>
using namespace std;

string str;

// substr 함수의 경우 선형 시간만큼 소요된다.
int countWord()
{
	int index = 0, count = 0, current = 0;
	while (true) {
		index = str.find(' ', index);	// 문자열에서 공백 지점을 찾는다.
		if (index == -1) break;	// 공백 지점이 없을 경우 탈출

		//str = str.substr(index + 1, str.length());	// 문자열을 공백 다음 지점부터 재정의
		count++;
		index++;
	}

	return count;
}

int main()
{
	getline(cin, str);
	// 공백만 입력될 경우
	if (str == " ") {
		cout << 0 << endl;
	}
	else {
		// 마지막 문자가 공백일 경우, 공백 제거
		if (str.at(str.length() - 1) == ' ')
			str = str.substr(0, str.length() - 1);
		// 첫 문자가 공백일 경우, 공백 제거
		if (str.at(0) == ' ')
			str = str.substr(1, str.length() - 1);

		int count = countWord();
		cout << count + 1 << endl;
	}

	return 0;
}