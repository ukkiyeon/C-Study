#ifndef PHONEBOOK_H // if not defined PHONEBOOK_H
#define PHONEBOOK_H

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

#endif // �������