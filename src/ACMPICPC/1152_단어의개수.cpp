/*
The Curious Case of Benjamin Button
01234
*/
#include <iostream>
#include <string>
using namespace std;

string str;

// substr �Լ��� ��� ���� �ð���ŭ �ҿ�ȴ�.
int countWord()
{
	int index = 0, count = 0, current = 0;
	while (true) {
		index = str.find(' ', index);	// ���ڿ����� ���� ������ ã�´�.
		if (index == -1) break;	// ���� ������ ���� ��� Ż��

		//str = str.substr(index + 1, str.length());	// ���ڿ��� ���� ���� �������� ������
		count++;
		index++;
	}

	return count;
}

int main()
{
	getline(cin, str);
	// ���鸸 �Էµ� ���
	if (str == " ") {
		cout << 0 << endl;
	}
	else {
		// ������ ���ڰ� ������ ���, ���� ����
		if (str.at(str.length() - 1) == ' ')
			str = str.substr(0, str.length() - 1);
		// ù ���ڰ� ������ ���, ���� ����
		if (str.at(0) == ' ')
			str = str.substr(1, str.length() - 1);

		int count = countWord();
		cout << count + 1 << endl;
	}

	return 0;
}