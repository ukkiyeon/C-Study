#include <iostream>
#include <string>

using namespace std;

#include "28��_��⿬_5-1_Phonebook.h"

int main()
{
	Phonebook T; // �̸��� T�� Phonebook Ÿ���� ��ü ����

	cout << "--- swing ��ȭ��ȣ�� ---" << endl;
	T.addPhone();
	cout << endl;

	int num;

	do
	{
		cout << "1. �ֽ� ��� ��ȭ��ȣ ��ȸ" << endl;
		cout << "2. �ֽ� ��� ��ȭ��ȣ ����" << endl;
		cout << "3. ����" << endl << ">> ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << T.getName() << " :: " << T.getPnum() << endl << endl;
			break;

		case 2:
			T.editPhone();
			break;

		case 3:
			break;
		}
	} while (num != 3);
}