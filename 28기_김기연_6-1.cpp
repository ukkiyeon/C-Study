#include <iostream>
#include <string>

using namespace std;

class ATM
{
private:
	string name; // ������ �̸�
	int pw; // ���� ��й�ȣ
	int money; // ���� �ܾ�
	
public:
	ATM(); //������
	void deposit(); // 1. �Ա�
	void withdraw(); // 2. ����
	void send(string receiver, int sendMon); // 3. ��ü-����
	void receive(int receiveMon); // 3. ��ü-����
	int getMoney(); // 4. ���ִ��� ���
	string getName(); // �̸� �ҷ�����

	void setName(); // ������ �̸� �Է�
	void setPW(); // ���� ��й�ȣ �Է�
	void checkPW(); // ���� ��й�ȣ �Է� Ȯ��
	void setMoney(); // ���� �ܾ� �Է�
};




ATM::ATM()
{}

void ATM::deposit() // 1. �Ա� 
{
	int deposit_price;

	cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
	cin >> deposit_price;
	money = money + deposit_price;
	cout << endl << "���� " << name << "���� �ܾ��� " << money << "�� �Դϴ�." << endl;
}

void ATM::withdraw() // 2. ���� 
{
	int withdraw_price; 
	int withdraw_pw; 

	cout << "�󸶸� �����Ͻðڽ��ϱ�? >> ";
	cin >> withdraw_price;
	
	while (1)
	{
		cout << "��й�ȣ�� �Է����ּ��� >> ";
		cin >> withdraw_pw;

		if (pw != withdraw_pw) // ��й�ȣ�� �ٸ���
		{
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�.";
			continue; // ���Է�
		}

		else // ��й�ȣ�� ������
		{
			money = money - withdraw_price;
			cout << endl << "���� " << name << "���� �ܾ��� " << money << "�� �Դϴ�." << endl;
			break;
		}
	}
}

void ATM::send(string receiver, int sendMon) // 3. ��ü-����
{
	money = money - sendMon;
}

void ATM::receive(int receiverMon) // 3. ��ü-����
{	
	money = money + receiverMon;
}

int ATM::getMoney() // 4. ���ִ��� ���
{
	return money;
}

string ATM::getName() // �̸� �ҷ�����
{
	return name;
}

void ATM::setName() // ������ �̸� �Է�
{
	cin >> name;
}

void ATM::setPW() // ���� ��й�ȣ �Է�
{
	cin >> pw;
}

void ATM::checkPW() // ���� ��й�ȣ �Է� Ȯ��
{
	int checkpw; // ��й�ȣ ���Է� ����

	cin >> checkpw;

	if (checkpw != pw) // ���� �ٸ���
	{
		do
		{
			cout << "��й�ȣ�� ���� �ٸ��ϴ�." << endl << endl;
			cout << "��й�ȣ�� �Է��� �ּ��� >> ";
			cin >> checkpw;
		} while (checkpw != pw); // ���� ������ �ݺ�
	}
}

void ATM::setMoney() // ���� �ܾ� �Է�
{
	cin >> money;
}




int main() 
{
	int cnt; // ���� ���� �ο� ��
	string name;
	string receiver;
	int pw;
	int money;
	int i; // �ݺ���
	int k;
	int m;
	int num;
	int sendMon;

	cout << "���࿡ ������ �ο��� �Է����ּ��� >> ";
	cin >> cnt;

	ATM *p = new ATM[cnt]; // cnt �Է��� ����ŭ ��ü �迭 ���� ����

	for (i = 0;i < cnt;i++)
	{
		cout << endl << i + 1 << "��° �մ�" << endl << endl;
		cout << "������ �����ֽʽÿ� >> ";
		(p + i)->setName(); // ������ �̸� �Է�
		cout << "��й�ȣ�� �Է����ּ��� >> ";
		(p + i)->setPW(); // ���� ��й�ȣ �Է�		
		cout << "�� �� �� �Է����ּ��� >> ";
		(p + i)->checkPW(); // ���� ��й�ȣ �Է� Ȯ��
		cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
		(p + i)->setMoney(); // ���� �ܾ� �Է�
		cout << endl << endl; 
	}

	while (1)
	{
		do
		{
			cout << endl << "--- SWING ATM ---" << endl;
			cout << "������ �Է����ּ��� (������ X�� �Է����ּ���) >> ";
			cin >> name;

			k = 10;

			for (i = 0;i < cnt;i++)
			{
				if (name == (p + i)->getName()) // ���� name�� getName()���� �ҷ��� �̸��� ������
					k = i; // i�� k�� ����
			}

			if (k == 10 && name != "X") // ���� k�� 10�̰� name�� X�� �ƴϸ�
				cout << "�������� �ʴ� �������Դϴ�." << endl;

			else
				break;
		} while (name != "X"); // name�� X�� �ԷµǸ� �ݺ��� Ż��

		if (name == "X") // while���� Ż��, ���α׷��� �����
		{
			cout << "ATM�� �����մϴ�." << endl;
			break;
		}
			
		do
		{
			cout << endl << "--- SWING ATM " << (p + k)->getName() << "��" << "---" << endl; // ������ ���� �̸�
			cout << "1. �Ա�" << endl << "2. ����" << endl << "3. ��ü" << endl << "4. �ܾ� Ȯ��" << endl << "5. ����" << endl;
			cout << endl << "��ȣ�� �������ּ��� >> ";
			cin >> num;

			switch (num)
			{
			case 1:
				(p + k)->deposit();
				break;

			case 2:
				(p + k)->withdraw();
				break;

			case 3:
				cout << "�������� �����ڽ��ϱ�? >> ";
				cin >> receiver;

				m = 10;

				for (i = 0;i < cnt;i++)
				{
					if (receiver == (p + i)->getName())
						m = i;
				}

				if (m == 10)
					break;

				cout << "�󸶸� �����ڽ��ϱ�? >> ";
				cin >> sendMon;
				(p + k)->send((p + m)->getName(), sendMon);

				while (1)
				{
					cout << "��й�ȣ�� �Է����ּ��� >> ";
					cin >> pw;

					if (pw != pw)
					{
						cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�. ";
						continue;
					}

					else
					{
						cout << endl << receiver << "�Բ� " << sendMon << "���� ���½��ϴ�." << endl;
						(p + m)->receive(sendMon);
						cout << endl << "���� " << (p + k)->getName() << "���� �ܾ��� " << (p + k)->getMoney() << "�� �Դϴ�." << endl;
						break;
					}	
				}
				break;

			case 4:
				cout << (p + k)->getName() << "���� ���� �ܾ��� " << (p+k)->getMoney() << "�� �Դϴ�." << endl;
				break;

			case 5:
				break;
			}
		} while (num != 5);
	}
}
