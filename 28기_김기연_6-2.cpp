#include <iostream>
#include <string>

using namespace std;

class PhoneBook
{
private:
	string number; // ��ȭ��ȣ
	string name; // �̸�

public:
	PhoneBook(); // ������
	void setPnum(string number); // ��ȭ��ȣ ����
	void setName(string name); // �̸� ����
	void addPhone(string name, string number); // �̸��� ��ȭ��ȣ ����
	string getPnum(); // ��ȭ��ȣ ��������
	string getName(); // �̸� ��������
	void editPnum(string number); // ��ȭ��ȣ ����
};

class PhoneBookManager
{
private:
	PhoneBook *phoneB; // ��ü �迭 ������ ���� ����
	int size; // ��ü �迭�� ũ��

public:
	PhoneBookManager(int num); // ������ - PhoneBook���� ��ü �迭 ����
	void showAll(); // ��ȭ��ȣ�� ��� ����
	void searchPnum(); // ��ȭ��ȣ ã��
	void addPnum(); // ��ȭ��ȣ ��ü �߰� ���� (�迭�� ���� ������ +1 �Ǿ�� ��)
	void editPnum(); // ��ȭ��ȣ ����
};




int main()
{
	int num; // ������ ��ȭ��ȣ ��
	int menu; // �޴� ��ȣ �Է� ����

	cout << " --- SWING ��ȭ��ȣ�� ---" << endl;
	cout << "������ ��ȭ��ȣ�� ���� �Է����ּ��� >> ";
	cin >> num;
	cout << endl;

	PhoneBookManager manager(num); // 

	do
	{
		cout << endl << " --- SWING ��ȭ��ȣ�� ---" << endl;
		cout << "1. ��ȭ��ȣ�� ����" << endl;
		cout << "2. ��ȭ��ȣ �˻�" << endl;
		cout << "3. ��ȭ��ȣ �߰��ϱ�" << endl;
		cout << "4. ��ȭ��ȣ �����ϱ�" << endl;
		cout << "5. ����" << endl;

		cout << "��ȣ�� �Է����ּ��� >> ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			manager.showAll();
			break;

		case 2:
			manager.searchPnum();
			break;

		case 3:
			manager.addPnum();
			break;

		case 4:
			manager.editPnum();
			break;

		case 5:
			cout << endl << endl << "���α׷��� �����մϴ�." << endl;
			break;

		default:
			cout << endl << endl << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}
	} while (menu != 5); // menu�� 5�� �Էµ� ������ �ݺ�
}




PhoneBook::PhoneBook() // ������
{}

void PhoneBook::setPnum(string number) // ��ȭ��ȣ ����
{
	this->number = number;
}

void PhoneBook::setName(string name) // �̸� ����
{
	this->name = name;
}

void PhoneBook::addPhone(string name, string number) // �̸��� ��ȭ��ȣ ����
{
	this->name = name;
	this->number = number;
}

string PhoneBook::getPnum() // ��ȭ��ȣ ��������
{
	return number;
}

string PhoneBook::getName() // �̸� ��������
{
	return name;
}

void PhoneBook::editPnum(string number)
{
	this->number.replace(0, 13, number);
}




PhoneBookManager::PhoneBookManager(int num) // ������ - PhoneBook���� ��ü �迭 ����
{
	int i;
	string name, number;
	size = num; // size�� ��ü �迭�� ũ��, �Էµ� num�� ����

	phoneB = new PhoneBook[size]; // size �Է��� ����ŭ ��ü �迭 ���� ����

	for (i = 0;i < size;i++)
	{
		cout << i + 1 << "��° ����� �̸��� �Է����ּ��� >> ";
		cin >> name;
		phoneB[i].setName(name); //
		cout << i + 1 << "��° ����� ��ȭ��ȣ�� �Է����ּ��� >> ";
		cin >> number;
		phoneB[i].setPnum(number); // 
		cout << endl;
	}
}

void PhoneBookManager::showAll() // 1. ��ȭ��ȣ�� ��� ����
{
	int i;

	cout << endl << endl;

	for (i = 0;i < size;i++) // size�� ��ü �迭�� ũ��
		cout << i + 1 << ". " << phoneB[i].getName() << "::" << phoneB[i].getPnum() << endl; // �̸��� ��ȭ��ȣ ��������
}

void PhoneBookManager::searchPnum() // 2. ��ȭ��ȣ ã��
{
	int i, k = 10;
	string name;

	cout << endl << endl << "������ ��ȣ�� �˻��ϰڽ��ϱ�? >> ";
	cin >> name;

	for (i = 0;i < size;i++)
	{
		if (name == phoneB[i].getName()) // �Էµ� name�� �ҷ��� �̸��� ������
			k = i; // �ε��� ���� k�� ����
	}

	if (k < size) // ���Ե� k�� ��ü �迭�� ũ�⺸�� �۾ƾ� ��
		cout << phoneB[k].getName() << "���� ��ȭ��ȣ : " << phoneB[k].getPnum() << endl; // �̸��� ��ȭ��ȣ ��������

	if (k == 10) // k���� �״�θ� ����ó ����
		cout << "����ó�� �������� �ʽ��ϴ�." << endl;
}

void PhoneBookManager::addPnum() // 3. ��ȭ��ȣ ��ü �߰� ���� (�迭�� ���� ������ +1 �Ǿ�� ��)
{
	string name, number;
	int i;

	cout << endl << endl << "�̸��� �Է����ּ��� >> ";
	cin >> name;
	cout << "��ȭ��ȣ�� �Է����ּ��� >> ";
	cin >> number;

	PhoneBook *tmp = new PhoneBook[size + 1]; //

	for (i = 0;i < size;i++)
		tmp[i] = phoneB[i]; //

	delete[] phoneB; //

	size++; //
	phoneB = new PhoneBook[size]; //

	for (i = 0;i < size;i++)
		phoneB[i] = tmp[i]; //

	phoneB[size - 1].addPhone(name, number); //

	cout << "��ȭ��ȣ�� �߰��Ǿ����ϴ�." << endl;
}

void PhoneBookManager::editPnum() // 4. ��ȭ��ȣ ����
{
	int i, k = 10;
	string name, number;

	cout << endl << endl << "������ ��ȣ�� �����ϰڽ��ϱ�? >> ";
	cin >> name;

	for (i = 0;i < size;i++)
	{
		if (name == phoneB[i].getName())
			k = i;
	}

	if (k < size)
	{
		cout << "������ ��ȣ�� �Է����ּ��� >> ";
		cin >> number;
		phoneB[k].editPnum(number);
		cout << "��ȭ��ȣ�� ����Ǿ����ϴ�." << endl;
	}

	if (k == 10)
		cout << "����ó�� �������� �ʽ��ϴ�." << endl;
}