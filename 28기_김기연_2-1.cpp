#include <iostream>

using namespace std;

int main()
{
	int i;
	int num[5];
	int odd = 0, even = 0;

	for (i = 0; i < 5; i++) // 숫자를 5개 입력받기
	{
		cout << "숫자를 입력해주세요: ";
		cin >> num[i]; // 숫자 입력을 배열로 받기
	}

	cout << endl << "---------결과---------" << endl;

	cout << "홀수: "; 

	for (i = 0; i < 5; i++)
	{
		if (num[i] % 2 == 1) // num[i]가 홀수일 때
		{
			cout << num[i] << " ";
			odd++; // 홀수 개수를 1개 증가시키기
		}
	}
	cout << endl << "홀수는 총 " << odd << "개 입니다." << endl << endl;

	cout << "짝수: ";

	for (i = 0; i < 5; i++)
	{
		if (num[i] % 2 == 0) // num[i]가 짝수일 때
		{
			cout << num[i] << " ";
			even++; // 짝수 개수를 1개 증가시키기
		}
	}
	cout << endl << "짝수는 총 " << even << "개 입니다." << endl;
}



