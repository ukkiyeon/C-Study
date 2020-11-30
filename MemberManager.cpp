#include <iostream>
#include <string>
using namespace std;

class Member {
	string name; // �̸�
	string tel; // ��ȭ��ȣ

public:
	Member() {}; // ������
	void set(string name, string tel) { this->name = name;this->tel = tel; } // name�� tel�� ����, ����
	string showName() { return name; } // �̸� �����ֱ�
	string showTel() { return tel; } // ��ȭ��ȣ �����ֱ�
};

class MemberManager { // ����Լ� �ִ��� �����ϱ�
	Member *Phonebook; // ��ü �迭 ������ ���� ����
	int num; // ����� �ο��� ��
	string name;
	string tel;

public:
	MemberManager() {};
	void getnum(); // ����� �ο��� ���� �Է¹ޱ�
	void getMember(); // �̸��� ��ȭ��ȣ �Է¹ޱ�
	void showMember(); // ��Ϻ���[1]
	void searchMember(); // �˻�[2]
	void delMember(); // ����[3]
	void editMember(); // ����[4]
};

void MemberManager::getnum() { // ����� �ο��� ���� �Է¹ޱ�
	cout << "����� �ο��� >>";
	cin >> num;
	cout << num << "���� �̸��� ��ȭ��ȣ�� �Է��մϴ�." << endl;
}

void MemberManager::getMember() { // �̸��� ��ȭ��ȣ �Է¹ޱ�
	Phonebook = new Member[num]; // ��ü �迭 ���� ����

	for (int i = 0;i < num;i++) {
		cout << "�̸��� ��ȭ��ȣ �Է� : ";
		cin >> name >> tel;
		Phonebook[i].set(name, tel); // �Է¹��� �̸� set�� �Ѱ��ֱ�
	}

	cout << "����Ǿ����ϴ�." << endl;
}

void MemberManager::showMember() { // ��Ϻ���[1]
	for (int i = 0;i < num;i++)
		cout << "[" << i + 1 << "] " << Phonebook[i].showName() << " " << Phonebook[i].showTel() << endl;
}

void MemberManager::searchMember() { // �˻�[2]
	string searchname;
	int k = 10; // �񱳿�

	cout << "�˻��� �̸��� �Է��ϼ���. ";
	cin >> searchname;

	for (int i = 0;i < num;i++) {
		if (searchname == Phonebook[i].showName()) // �Էµ� searchname�� �ҷ��� �̸��� ���ٸ�
			k = i; // �ε��� ���� k�� ����
	}

	if (k < num) // ���Ե� k�� ��ü �迭�� ũ�⺸�� �۾ƾ� ��
		cout << Phonebook[k].showName() << "�� ��ȣ�� " << Phonebook[k].showTel() << "�Դϴ�." << endl;

	if (k == 10) // k���� �״�θ� ����ó ����
		cout << "�˻��� �̸��� �����ϴ�." << endl;
}

void MemberManager::delMember() { // ����[3]
	int del;

	cout << "��ȣ�� �����ϸ� �����˴ϴ�. >> ";
	cin >> del;

	for (int i = 0;i < num;i++) {
		if (i == del - 1) {
			for (int k = i;k < num - 1;k++)
				Phonebook[k] = Phonebook[k + 1];

			num--;
		}
	}
}

void MemberManager::editMember() { // ����[4]
	int i;
	string editName, editTel;

	cout << "������ ��ȣ�� �����ϼ���. >> ";
	cin >> i;
	cout << "�̸��� ��ȭ��ȣ �Է� >> ";
	cin >> editName >> editTel;

	Phonebook[i - 1].set(editName, editTel);
}

int main() {
	int list; // ��ȣ ����
	int search;

	MemberManager manager; // manager ��ü ����

	manager.getnum();
	manager.getMember();

	do {
		cout << endl << "��Ϻ��� [1], �˻� [2], ����[3], ����[4], ����[5] >> ";
		cin >> list;

		switch (list) {
		case 1:
			manager.showMember();
			break;

		case 2:
			do {
				cout << endl << "��� �˻�[6], �˻� ����[7] >> ";
				cin >> search;
				
				switch (search) {
				case 6:
					manager.searchMember();
					break;

				case 7:
					cout << endl;
					break;
				}
			} while (search != 7);
			break;

		case 3:
			cout << endl;
			manager.showMember();
			manager.delMember();
			cout << endl;
			manager.showMember();
			break;

		case 4:
			cout << endl;
			manager.showMember();
			manager.editMember();
			cout << endl;
			manager.showMember();
			break;

		case 5:
			cout << endl << "���α׷��� �����մϴ�." << endl;
			break;
		}
	} while (list != 5); // list�� 5�� �Էµ� ������ �ݺ��ϱ�
}