#include <iostream>

using namespace std;

void swap(int *a, int *b) // 반환할 값이 없으므로 void 사용, 함수 이름은 swap, 매개변수는 int *a와 int *b
{
	int temp;

	temp = *a; // temp에 *a를 대입
	*a = *b; // *a에는 *b를 대입
	*b = temp; // *b에는 *a가 있던 temp를 대입
}

int main()
{
	int x, y;

	cout << "first number >> ";
	cin >> x;

	cout << "second number >> ";
	cin >> y;

	cout << endl;
	
	cout << "swap 전 >> " << x << "  " << y << endl; // 함수 호출 전 출력
	swap(&x, &y); // 함수 호출, 매개변수 int *a에 &x 대입, 매개변수 int *b에 &y 대입
	cout << "swap 후 >> " << x << "  " << y << endl; // 함수 호출 후 출력, 숫자가 교환됨
}