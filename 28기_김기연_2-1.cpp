#include <iostream>

using namespace std;

int main()
{
	int i;
	int num[5];
	int odd = 0, even = 0;

	for (i = 0; i < 5; i++) // ���ڸ� 5�� �Է¹ޱ�
	{
		cout << "���ڸ� �Է����ּ���: ";
		cin >> num[i]; // ���� �Է��� �迭�� �ޱ�
	}

	cout << endl << "---------���---------" << endl;

	cout << "Ȧ��: "; 

	for (i = 0; i < 5; i++)
	{
		if (num[i] % 2 == 1) // num[i]�� Ȧ���� ��
		{
			cout << num[i] << " ";
			odd++; // Ȧ�� ������ 1�� ������Ű��
		}
	}
	cout << endl << "Ȧ���� �� " << odd << "�� �Դϴ�." << endl << endl;

	cout << "¦��: ";

	for (i = 0; i < 5; i++)
	{
		if (num[i] % 2 == 0) // num[i]�� ¦���� ��
		{
			cout << num[i] << " ";
			even++; // ¦�� ������ 1�� ������Ű��
		}
	}
	cout << endl << "¦���� �� " << even << "�� �Դϴ�." << endl;
}



