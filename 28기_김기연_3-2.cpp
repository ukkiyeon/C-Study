#include <iostream>

using namespace std;

void swap(int a, int b) // ��ȯ�� ���� �����Ƿ� void ���, �Լ� �̸��� swap, �Ű������� int a�� int b
{
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
	
	cout << "swap �� >> " << x << "  " << y << endl;
	swap(x, y); // �Լ� ȣ��, �Ű����� int a�� x ����, �Ű����� int b�� y ����
	cout << endl;
}