#include <iostream>

using namespace std;

int main()
{
	int i, k;

	for (i = 0;i < 5;i++) // i�� 0���� 4���� �ݺ��� ����
	{
		for (k = 0;k <= i;k++) // k�� 0���� i�� ������ ������
		{
			cout << "*"; // * ���
		}
		cout << endl; // �ٹٲٱ�
	}
}