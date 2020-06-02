#include <iostream>
#include <string>

using namespace std;

class Phonebook
{
public:
	void addPhone(); // 입력한 번호 등록 함수
	void editPhone(); // 번호 수정 함수
	string getPnum(); // 입력된 번호 불러오는 함수
	string getName(); // 입력된 이름 불러오는 함수

private:
	string name;
	string number;
};

void Phonebook::addPhone()
{
	cout << "이름을 입력해 주세요 >> ";
	cin >> name;
	cout << "전화번호를 입력해 주세요 >> ";
	cin >> number;
}

void Phonebook::editPhone()
{
	string name2;

	cout << "이름을 입력해 주세요 >> ";
	cin >> name2;

	do
	{
		cout << "연락처가 존재하지 않습니다. 다시 입력해 주세요. >> ";
		cin >> name2;
	} while (name2 != name);

	cout << "변경할 전화번호를 입력해 주세요 >> ";
	cin >> number;
	cout << endl;
}

string Phonebook::getPnum()
{
	return number;
}

string Phonebook::getName()
{
	return name;
}

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