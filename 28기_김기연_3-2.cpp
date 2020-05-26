#include <iostream>

using namespace std;

void swap(int a, int b) // 반환할 값이 없으므로 void 사용, 함수 이름은 swap, 매개변수는 int a와 int b
{
	cout << "swap 후 >> " << b << "  " << a; // a와 b의 위치 바꾸기 (숫자 교환)
}

int main()
{
	int x, y;

	cout << "first number >> ";
	cin >> x;

	cout << "second number >> ";
	cin >> y;

	cout << endl;
	
	cout << "swap 전 >> " << x << "  " << y << endl;
	swap(x, y); // 함수 호출, 매개변수 int a에 x 대입, 매개변수 int b에 y 대입
	cout << endl;
}