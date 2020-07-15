#include <iostream>
using namespace std;

int main()
{
	int len; // 수열의 길이
	int i, k, m; // 반복문
	int min; // 최소값 인덱스
	int temp; // 임시 저장
	
	cout << "수열의 길이 입력: ";
	cin >> len;

	int *sort = new int[len]; // n만큼 정수형 배열 동적 할당

	cout << "수열 입력: ";

	for (i = 0;i < len;i++)
		cin >> sort[i];

	cout << "-----------------------------" << endl;
	cout << "선택 정렬 결과" << endl;

	for (i = 0;i < len - 1;i++)
	{
		min = i;

		for (k = i + 1;k < len;k++)
		{
			if (sort[min] > sort[k])
				min = k; // 최소값의 인덱스 k를 min에 대입
		}

		temp = sort[min]; // sort[min](최소값)과 sort[i](맨 앞)의 자리를 바꾸기
		sort[min] = sort[i];
		sort[i] = temp;

		for (m = 0;m < len;m++) // 한 단계씩 출력
			cout << sort[m] << " ";

		cout << endl;
	}
}