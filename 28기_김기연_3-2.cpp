#include <iostream>

using namespace std;

void swap(int a, int b) // ��ȯ�� ���� �����Ƿ� void ���, �Լ� �̸��� swap, �Ű������� int a�� int b
{
	cout << "swap �� >> " << a << "  " << b << endl;
	cout << "swap �� >> " << b << "  " << a; // a�� b�� ��ġ �ٲٱ� (���� ��ȯ)
}

int main()
{
	int x, y;

	cout << "first number >> ";
	cin >> x;

	cout << "second number >> ";
	cin >> y;

	cout << endl;
	
	swap(x, y); // �Ű����� int a�� x ����, �Ű����� int b�� y ����
	cout << endl;
}