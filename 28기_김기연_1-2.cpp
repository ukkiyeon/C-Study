#include <iostream>
using namespace std;

int main() {
	int num1;
	cout << "First number>>";
	cin >> num1;
	float num2; //int/int�� ����� �����̱� ������ �ϳ��� �Ǽ��� �ٲ���� ��
	cout << "Second number>>";
	cin >> num2;

	cout << "==========��� ���==========" << endl;
	cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
	cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
	cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
	cout << num1 << "/" << num2 << "=" << num1 / num2 << endl;

}