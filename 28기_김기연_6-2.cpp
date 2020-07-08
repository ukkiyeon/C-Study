#include <iostream>
#include <string>

using namespace std;

class PhoneBook
{
private:
	string number; // 전화번호
	string name; // 이름

public:
	PhoneBook(); // 생성자
	void setPnum(string number); // 전화번호 저장
	void setName(string name); // 이름 저장
	void addPhone(string name, string number); // 이름과 전화번호 저장
	string getPnum(); // 전화번호 가져오기
	string getName(); // 이름 가져오기
	void editPnum(string number); // 전화번호 수정
};

class PhoneBookManager
{
private:
	PhoneBook *phoneB; // 객체 배열 생성을 위한 선언
	int size; // 객체 배열의 크기

public:
	PhoneBookManager(int num); // 생성자 - PhoneBook으로 객체 배열 생성
	void showAll(); // 전화번호부 목록 보기
	void searchPnum(); // 전화번호 찾기
	void addPnum(); // 전화번호 객체 추가 생성 (배열의 원소 개수가 +1 되어야 함)
	void editPnum(); // 전화번호 수정
};




int main()
{
	int num; // 저장할 전화번호 수
	int menu; // 메뉴 번호 입력 변수

	cout << " --- SWING 전화번호부 ---" << endl;
	cout << "저장할 전화번호의 수를 입력해주세요 >> ";
	cin >> num;
	cout << endl;

	PhoneBookManager manager(num); // 

	do
	{
		cout << endl << " --- SWING 전화번호부 ---" << endl;
		cout << "1. 전화번호부 보기" << endl;
		cout << "2. 전화번호 검색" << endl;
		cout << "3. 전화번호 추가하기" << endl;
		cout << "4. 전화번호 수정하기" << endl;
		cout << "5. 종료" << endl;

		cout << "번호를 입력해주세요 >> ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			manager.showAll();
			break;

		case 2:
			manager.searchPnum();
			break;

		case 3:
			manager.addPnum();
			break;

		case 4:
			manager.editPnum();
			break;

		case 5:
			cout << endl << endl << "프로그램을 종료합니다." << endl;
			break;

		default:
			cout << endl << endl << "잘못 입력하셨습니다." << endl;
		}
	} while (menu != 5); // menu에 5가 입력될 때까지 반복
}




PhoneBook::PhoneBook() // 생성자
{}

void PhoneBook::setPnum(string number) // 전화번호 저장
{
	this->number = number;
}

void PhoneBook::setName(string name) // 이름 저장
{
	this->name = name;
}

void PhoneBook::addPhone(string name, string number) // 이름과 전화번호 저장
{
	this->name = name;
	this->number = number;
}

string PhoneBook::getPnum() // 전화번호 가져오기
{
	return number;
}

string PhoneBook::getName() // 이름 가져오기
{
	return name;
}

void PhoneBook::editPnum(string number)
{
	this->number.replace(0, 13, number);
}




PhoneBookManager::PhoneBookManager(int num) // 생성자 - PhoneBook으로 객체 배열 생성
{
	int i;
	string name, number;
	size = num; // size는 객체 배열의 크기, 입력된 num을 대입

	phoneB = new PhoneBook[size]; // size 입력한 값만큼 객체 배열 동적 생성

	for (i = 0;i < size;i++)
	{
		cout << i + 1 << "번째 사람의 이름을 입력해주세요 >> ";
		cin >> name;
		phoneB[i].setName(name); //
		cout << i + 1 << "번째 사람의 전화번호를 입력해주세요 >> ";
		cin >> number;
		phoneB[i].setPnum(number); // 
		cout << endl;
	}
}

void PhoneBookManager::showAll() // 1. 전화번호부 목록 보기
{
	int i;

	cout << endl << endl;

	for (i = 0;i < size;i++) // size는 객체 배열의 크기
		cout << i + 1 << ". " << phoneB[i].getName() << "::" << phoneB[i].getPnum() << endl; // 이름과 전화번호 가져오기
}

void PhoneBookManager::searchPnum() // 2. 전화번호 찾기
{
	int i, k = 10;
	string name;

	cout << endl << endl << "누구의 번호를 검색하겠습니까? >> ";
	cin >> name;

	for (i = 0;i < size;i++)
	{
		if (name == phoneB[i].getName()) // 입력된 name과 불러온 이름이 같으면
			k = i; // 인덱스 값을 k에 대입
	}

	if (k < size) // 대입된 k는 객체 배열의 크기보다 작아야 함
		cout << phoneB[k].getName() << "님의 전화번호 : " << phoneB[k].getPnum() << endl; // 이름과 전화번호 가져오기

	if (k == 10) // k값이 그대로면 연락처 없음
		cout << "연락처가 존재하지 않습니다." << endl;
}

void PhoneBookManager::addPnum() // 3. 전화번호 객체 추가 생성 (배열의 원소 개수가 +1 되어야 함)
{
	string name, number;
	int i;

	cout << endl << endl << "이름을 입력해주세요 >> ";
	cin >> name;
	cout << "전화번호를 입력해주세요 >> ";
	cin >> number;

	PhoneBook *tmp = new PhoneBook[size + 1]; //

	for (i = 0;i < size;i++)
		tmp[i] = phoneB[i]; //

	delete[] phoneB; //

	size++; //
	phoneB = new PhoneBook[size]; //

	for (i = 0;i < size;i++)
		phoneB[i] = tmp[i]; //

	phoneB[size - 1].addPhone(name, number); //

	cout << "전화번호가 추가되었습니다." << endl;
}

void PhoneBookManager::editPnum() // 4. 전화번호 수정
{
	int i, k = 10;
	string name, number;

	cout << endl << endl << "누구의 번호를 수정하겠습니까? >> ";
	cin >> name;

	for (i = 0;i < size;i++)
	{
		if (name == phoneB[i].getName())
			k = i;
	}

	if (k < size)
	{
		cout << "변경할 번호를 입력해주세요 >> ";
		cin >> number;
		phoneB[k].editPnum(number);
		cout << "전화번호가 변경되었습니다." << endl;
	}

	if (k == 10)
		cout << "연락처가 존재하지 않습니다." << endl;
}