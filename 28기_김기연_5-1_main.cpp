#include <iostream>
#include <string>

using namespace std;

#include "28기_김기연_5-1_Phonebook.h"

int main()
{
	Phonebook T; // 이름이 T인 Phonebook 타입의 객체 생성

	cout << "--- swing 전화번호부 ---" << endl;
	T.addPhone();
	cout << endl;

	int num;

	do
	{
		cout << "1. 최신 등록 전화번호 조회" << endl;
		cout << "2. 최신 등록 전화번호 수정" << endl;
		cout << "3. 종료" << endl << ">> ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << T.getName() << " :: " << T.getPnum() << endl << endl;
			break;

		case 2:
			T.editPhone();
			break;

		case 3:
			break;
		}
	} while (num != 3);
}