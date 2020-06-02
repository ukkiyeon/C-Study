#include <iostream>
#include <string>

using namespace std;

class Phonebook
{
public:
	void addPhone(); // �Է��� ��ȣ ��� �Լ�
	void editPhone(); // ��ȣ ���� �Լ�
	string getPnum(); // �Էµ� ��ȣ �ҷ����� �Լ�
	string getName(); // �Էµ� �̸� �ҷ����� �Լ�

private:
	string name;
	string number;
};

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