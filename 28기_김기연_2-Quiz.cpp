#include <iostream>

using namespace std;

int main()
{
	int i, k;

	for (i = 0;i < 5;i++) // i가 0에서 4까지 반복될 동안
	{
		for (k = 0;k <= i;k++) // k가 0부터 i와 같아질 때까지
		{
			cout << "*"; // * 출력
		}
		cout << endl; // 줄바꾸기
	}
}