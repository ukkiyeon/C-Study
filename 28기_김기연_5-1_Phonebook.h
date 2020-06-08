#ifndef PHONEBOOK_H // if not defined PHONEBOOK_H
#define PHONEBOOK_H

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

#endif // 여기까지