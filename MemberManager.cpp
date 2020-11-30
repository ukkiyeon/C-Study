#include <iostream>
#include <string>
using namespace std;

class Member {
	string name; // 이름
	string tel; // 전화번호

public:
	Member() {}; // 생성자
	void set(string name, string tel) { this->name = name;this->tel = tel; } // name과 tel에 접근, 저장
	string showName() { return name; } // 이름 보여주기
	string showTel() { return tel; } // 전화번호 보여주기
};

class MemberManager { // 멤버함수 최대한 구현하기
	Member *Phonebook; // 객체 배열 생성을 위한 선언
	int num; // 등록할 인원의 수
	string name;
	string tel;

public:
	MemberManager() {};
	void getnum(); // 등록할 인원의 수를 입력받기
	void getMember(); // 이름과 전화번호 입력받기
	void showMember(); // 목록보기[1]
	void searchMember(); // 검색[2]
	void delMember(); // 삭제[3]
	void editMember(); // 수정[4]
};

void MemberManager::getnum() { // 등록할 인원의 수를 입력받기
	cout << "등록할 인원수 >>";
	cin >> num;
	cout << num << "명의 이름과 전화번호를 입력합니다." << endl;
}

void MemberManager::getMember() { // 이름과 전화번호 입력받기
	Phonebook = new Member[num]; // 객체 배열 동적 생성

	for (int i = 0;i < num;i++) {
		cout << "이름과 전화번호 입력 : ";
		cin >> name >> tel;
		Phonebook[i].set(name, tel); // 입력받은 이름 set에 넘겨주기
	}

	cout << "저장되었습니다." << endl;
}

void MemberManager::showMember() { // 목록보기[1]
	for (int i = 0;i < num;i++)
		cout << "[" << i + 1 << "] " << Phonebook[i].showName() << " " << Phonebook[i].showTel() << endl;
}

void MemberManager::searchMember() { // 검색[2]
	string searchname;
	int k = 10; // 비교용

	cout << "검색할 이름을 입력하세요. ";
	cin >> searchname;

	for (int i = 0;i < num;i++) {
		if (searchname == Phonebook[i].showName()) // 입력된 searchname과 불러온 이름이 같다면
			k = i; // 인덱스 값을 k에 대입
	}

	if (k < num) // 대입된 k는 객체 배열의 크기보다 작아야 함
		cout << Phonebook[k].showName() << "의 번호는 " << Phonebook[k].showTel() << "입니다." << endl;

	if (k == 10) // k값이 그대로면 연락처 없음
		cout << "검색한 이름이 없습니다." << endl;
}

void MemberManager::delMember() { // 삭제[3]
	int del;

	cout << "번호를 선택하면 삭제됩니다. >> ";
	cin >> del;

	for (int i = 0;i < num;i++) {
		if (i == del - 1) {
			for (int k = i;k < num - 1;k++)
				Phonebook[k] = Phonebook[k + 1];

			num--;
		}
	}
}

void MemberManager::editMember() { // 수정[4]
	int i;
	string editName, editTel;

	cout << "수정할 번호를 선택하세요. >> ";
	cin >> i;
	cout << "이름과 전화번호 입력 >> ";
	cin >> editName >> editTel;

	Phonebook[i - 1].set(editName, editTel);
}

int main() {
	int list; // 번호 선택
	int search;

	MemberManager manager; // manager 객체 생성

	manager.getnum();
	manager.getMember();

	do {
		cout << endl << "목록보기 [1], 검색 [2], 삭제[3], 수정[4], 종료[5] >> ";
		cin >> list;

		switch (list) {
		case 1:
			manager.showMember();
			break;

		case 2:
			do {
				cout << endl << "계속 검색[6], 검색 종료[7] >> ";
				cin >> search;
				
				switch (search) {
				case 6:
					manager.searchMember();
					break;

				case 7:
					cout << endl;
					break;
				}
			} while (search != 7);
			break;

		case 3:
			cout << endl;
			manager.showMember();
			manager.delMember();
			cout << endl;
			manager.showMember();
			break;

		case 4:
			cout << endl;
			manager.showMember();
			manager.editMember();
			cout << endl;
			manager.showMember();
			break;

		case 5:
			cout << endl << "프로그램을 종료합니다." << endl;
			break;
		}
	} while (list != 5); // list에 5가 입력될 때까지 반복하기
}