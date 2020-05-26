#include <iostream>

using namespace std;

void sort(int *num) // 정렬 함수 sort()
{
	int i, k, temp;

	for (i = 0;i < 4;i++) // num[0]부터 num[3]까지 차례대로 값을 지정한 후 나머지 값들과 비교하여 최소값을 앞쪽으로 이동
	{
		for (k = i + 1;k < 5;k++) // num[i]와 num[i+1]부터의 값들을 비교
		{
			if (num[i] > num[k]) // 최소값을 num[i]로 이동
			{
				temp = num[i];
				num[i] = num[k];
				num[k] = temp;
			}
		}
	}
}

void print(int *num) // 출력 함수 print()
{
	cout << "< 정렬 후 >" << endl << endl;

	int i;
	for (i = 0;i < 5;i++)
		cout << i + 1 << ". " << num[i] << endl;
}

int main()
{
	int i;
	int num[5];

	cout << "숫자 다섯개를 입력해주세요 (띄어쓰기로 구분) >> ";

	for (i = 0;i < 5;i++) // 숫자를 5개 입력받기
		cin >> num[i]; // 숫자 입력을 배열로 받기

	cout << endl << "< 정렬 전 >" << endl << endl;

	for (i = 0;i < 5;i++) // 정렬 전의 숫자들을 출력
		cout << i + 1 << ". " << num[i] << endl;

	cout << endl << endl;

	sort(num); // 정렬 함수 호출, 숫자들이 정렬됨
	print(num); // 출력 함수 호출, 정렬 후의 숫자들이 출력됨
}