#include <iostream>
#include <string>

using namespace std;

#include "28��_��⿬_5-1_Phonebook.h"

void Phonebook::addPhone()
{
	cout << "�̸��� �Է��� �ּ��� >> ";
	cin >> name;
	cout << "��ȭ��ȣ�� �Է��� �ּ��� >> ";
	cin >> number;
}

void Phonebook::editPhone()
{
	string name2;

	cout << "�̸��� �Է��� �ּ��� >> ";
	cin >> name2;

	do
	{
		cout << "����ó�� �������� �ʽ��ϴ�. �ٽ� �Է��� �ּ���. >> ";
		cin >> name2;
	} while (name2 != name);

	cout << "������ ��ȭ��ȣ�� �Է��� �ּ��� >> ";
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