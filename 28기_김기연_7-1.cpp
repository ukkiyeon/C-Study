#include <iostream>
using namespace std;

int main()
{
	int len; // ������ ����
	int i, k, m; // �ݺ���
	int min; // �ּҰ� �ε���
	int temp; // �ӽ� ����
	
	cout << "������ ���� �Է�: ";
	cin >> len;

	int *sort = new int[len]; // n��ŭ ������ �迭 ���� �Ҵ�

	cout << "���� �Է�: ";

	for (i = 0;i < len;i++)
		cin >> sort[i];

	cout << "-----------------------------" << endl;
	cout << "���� ���� ���" << endl;

	for (i = 0;i < len - 1;i++)
	{
		min = i;

		for (k = i + 1;k < len;k++)
		{
			if (sort[min] > sort[k])
				min = k; // �ּҰ��� �ε��� k�� min�� ����
		}

		temp = sort[min]; // sort[min](�ּҰ�)�� sort[i](�� ��)�� �ڸ��� �ٲٱ�
		sort[min] = sort[i];
		sort[i] = temp;

		for (m = 0;m < len;m++) // �� �ܰ辿 ���
			cout << sort[m] << " ";

		cout << endl;
	}
}