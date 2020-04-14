#include <iostream>
using namespace std;

int main() {
	int num1;
	cout << "First number>>";
	cin >> num1;
	float num2; //int/int의 결과는 정수이기 때문에 하나를 실수로 바꿔줘야 함
	cout << "Second number>>";
	cin >> num2;

	cout << "==========계산 결과==========" << endl;
	cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
	cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
	cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
	cout << num1 << "/" << num2 << "=" << num1 / num2 << endl;

}