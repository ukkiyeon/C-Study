#include <iostream>

using namespace std;

void swap(int *a, int *b) // ��ȯ�� ���� �����Ƿ� void ���, �Լ� �̸��� swap, �Ű������� int *a�� int *b
{
	int temp;

	temp = *a; // temp�� *a�� ����
	*a = *b; // *a���� *b�� ����
	*b = temp; // *b���� *a�� �ִ� temp�� ����
}

int main()
{
	int x, y;

	cout << "first number >> ";
	cin >> x;

	cout << "second number >> ";
	cin >> y;

	cout << endl;
	
	cout << "swap �� >> " << x << "  " << y << endl; // �Լ� ȣ�� �� ���
	swap(&x, &y); // �Լ� ȣ��, �Ű����� int *a�� &x ����, �Ű����� int *b�� &y ����
	cout << "swap �� >> " << x << "  " << y << endl; // �Լ� ȣ�� �� ���, ���ڰ� ��ȯ��
}