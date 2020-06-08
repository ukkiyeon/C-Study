#include <iostream>
#include <string>

using namespace std;

#include "28기_김기연_5-1_Phonebook.h"

void Phonebook::addPhone()
{
	cout << "이름을 입력해 주세요 >> ";
	cin >> name;
	cout << "전화번호를 입력해 주세요 >> ";
	cin >> number;
}

void Phonebook::editPhone()
{
	string name2;

	cout << "이름을 입력해 주세요 >> ";
	cin >> name2;

	do
	{
		cout << "연락처가 존재하지 않습니다. 다시 입력해 주세요. >> ";
		cin >> name2;
	} while (name2 != name);

	cout << "변경할 전화번호를 입력해 주세요 >> ";
	cin >> number;
	cout << endl;
}

string Phonebook::getPnum()
{
	return number;
}

string Phonebook::getName()
{
	return name;
}