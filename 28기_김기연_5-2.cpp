#include <iostream>
#include <string>

using namespace std;

class VendingMachine
{
private:
	string name; // ���� �̸�
	int price; // ����
	int total = 0; // ���� �ջ� ��

public:
	VendingMachine() {}; // ������
	void purchase(double v1); // �� �ݾ� ���, ���� �Է�, �Ž����� ���
	void menu(); // �޴���
	string getName(); // �߰��� ����
	double getPrice(); // �߰��� ���� ����
	double getTotal(); // �� �ݾ�
	void setName(string n); // ���� �߰� �� �޴�
	void setPrice(int p); // ���� �߰� �� ����
	void setTotal(int t); // �ݾ� �߰�
};

void VendingMachine::purchase(double v1) // �� �ݾ� ���, ���� �Է�, �Ž����� ���
{
	int money; // �Էµ� ����

	cout << endl << "��� ���Դϴ�. ��ٷ��ּ��� . . ." << endl << endl;
	cout << "�� �ݾ� : " << v1 << endl;
	cout << "���� �Է��ϼ��� : ";
	cin >> money;

	int change = money - v1;

	do
	{
		if (money < v1)
		{
			cout << "�ݾ��� �����մϴ�. �ٽ� �־��ּ��� : ";
			cin >> money;
			continue;
		}

		else if (money > v1)
		{
			if (change % 100 == 0)
				cout << "�Ž����� �Դϴ�." << endl;

			else
				cout << "�Ž������� 500���� 100���� �����մϴ�." << endl;

			cout << "500�� : " << change / 500 << "��" << endl;
			cout << "100�� : " << change % 500 / 100 << "��" << endl;
			cout << "�ȳ���������." << endl;
		}

		else
			cout << "�Ž������� �����ϴ�. �ȳ���������.";
	} while (money < v1);
}

void VendingMachine::menu() // �޴���
{
	cout << "===== SWING ���Ǳ� =====" << endl;
	cout << "1. ��ī�ݶ� : 1500��" << endl;
	cout << "2. ��Ÿ500 : 900��" << endl;
	cout << "3. �Ŀ����̵� : 2000��" << endl;
	cout << "4. " << name << " : " << price << "��" << endl;
	cout << "5. ���" << endl;
}

string VendingMachine::getName() // �߰��� ����
{
	cout << endl << "�߰��� ���� �̸��� �Է����ּ��� : ";
	cin >> name;
	return name;
}

double VendingMachine::getPrice() // �߰��� ���� ����
{
	cout << "�Ǹ��� ������ �Է��ϼ��� : ";
	cin >> price;
	return price;
}

double VendingMachine::getTotal() // �� �ݾ�
{
	return total;
}

void VendingMachine::setName(string n) // ���� �߰� �� �޴�
{
	name = n;
}

void VendingMachine::setPrice(int p) // ���� �߰� �� ����
{
	price = p;
}

void VendingMachine::setTotal(int t) // �ݾ� �߰�
{
	total += t;
}

int main()
{
	VendingMachine V; // �̸��� V�� VendingMachine Ÿ���� ��ü ����
	VendingMachine *p = &V;
	
	cout << "===== SWING ���Ǳ� =====" << endl;
	cout << "1. ��ī�ݶ� : 1500��" << endl;
	cout << "2. ��Ÿ500 : 900��" << endl;
	cout << "3. �Ŀ����̵� : 2000��" << endl;
	cout << "4. �غ���" << endl;
	cout << "5. ���" << endl;
	
	p->setName(V.getName());
	p->setPrice(V.getPrice());
	cout << endl;

	int num, amount;

	do
	{
		V.menu();

		cout << "��ȣ�� �������ּ��� : ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 1500);
			break;
		case 2:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 900);
			break;
		case 3:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 2000);
			break;
		case 4:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount*V.getPrice());
			break;
		} 
	} while (num != 5);

	V.purchase(V.getTotal());
}