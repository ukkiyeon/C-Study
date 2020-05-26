#include <iostream>

using namespace std;

void sort(int *num) // ���� �Լ� sort()
{
	int i, k, temp;

	for (i = 0;i < 4;i++) // num[0]���� num[3]���� ���ʴ�� ���� ������ �� ������ ����� ���Ͽ� �ּҰ��� �������� �̵�
	{
		for (k = i + 1;k < 5;k++) // num[i]�� num[i+1]������ ������ ��
		{
			if (num[i] > num[k]) // �ּҰ��� num[i]�� �̵�
			{
				temp = num[i];
				num[i] = num[k];
				num[k] = temp;
			}
		}
	}
}

void print(int *num) // ��� �Լ� print()
{
	cout << "< ���� �� >" << endl << endl;

	int i;
	for (i = 0;i < 5;i++)
		cout << i + 1 << ". " << num[i] << endl;
}

int main()
{
	int i;
	int num[5];

	cout << "���� �ټ����� �Է����ּ��� (����� ����) >> ";

	for (i = 0;i < 5;i++) // ���ڸ� 5�� �Է¹ޱ�
		cin >> num[i]; // ���� �Է��� �迭�� �ޱ�

	cout << endl << "< ���� �� >" << endl << endl;

	for (i = 0;i < 5;i++) // ���� ���� ���ڵ��� ���
		cout << i + 1 << ". " << num[i] << endl;

	cout << endl << endl;

	sort(num); // ���� �Լ� ȣ��, ���ڵ��� ���ĵ�
	print(num); // ��� �Լ� ȣ��, ���� ���� ���ڵ��� ��µ�
}