#include <iostream>
#include <string>

using namespace std;

class VendingMachine
{
private:
	string name; // 음료 이름
	int price; // 가격
	int total = 0; // 음료 합산 값

public:
	VendingMachine() {}; // 생성자
	void purchase(double v1); // 총 금액 출력, 지폐 입력, 거스름돈 출력
	void menu(); // 메뉴판
	string getName(); // 추가할 음료
	double getPrice(); // 추가할 음료 가격
	double getTotal(); // 총 금액
	void setName(string n); // 음료 추가 후 메뉴
	void setPrice(int p); // 음료 추가 후 가격
	void setTotal(int t); // 금액 추가
};

void VendingMachine::purchase(double v1) // 총 금액 출력, 지폐 입력, 거스름돈 출력
{
	int money; // 입력된 지폐

	cout << endl << "계산 중입니다. 기다려주세요 . . ." << endl << endl;
	cout << "총 금액 : " << v1 << endl;
	cout << "지폐를 입력하세요 : ";
	cin >> money;

	int change = money - v1;

	do
	{
		if (money < v1)
		{
			cout << "금액이 부족합니다. 다시 넣어주세요 : ";
			cin >> money;
			continue;
		}

		else if (money > v1)
		{
			if (change % 100 == 0)
				cout << "거스름돈 입니다." << endl;

			else
				cout << "거스름돈은 500원과 100원만 가능합니다." << endl;

			cout << "500원 : " << change / 500 << "개" << endl;
			cout << "100원 : " << change % 500 / 100 << "개" << endl;
			cout << "안녕히가세요." << endl;
		}

		else
			cout << "거스름돈이 없습니다. 안녕히가세요.";
	} while (money < v1);
}

void VendingMachine::menu() // 메뉴판
{
	cout << "===== SWING 자판기 =====" << endl;
	cout << "1. 코카콜라 : 1500원" << endl;
	cout << "2. 비타500 : 900원" << endl;
	cout << "3. 파워에이드 : 2000원" << endl;
	cout << "4. " << name << " : " << price << "원" << endl;
	cout << "5. 계산" << endl;
}

string VendingMachine::getName() // 추가할 음료
{
	cout << endl << "추가할 음료 이름을 입력해주세요 : ";
	cin >> name;
	return name;
}

double VendingMachine::getPrice() // 추가할 음료 가격
{
	cout << "판매할 가격을 입력하세요 : ";
	cin >> price;
	return price;
}

double VendingMachine::getTotal() // 총 금액
{
	return total;
}

void VendingMachine::setName(string n) // 음료 추가 후 메뉴
{
	name = n;
}

void VendingMachine::setPrice(int p) // 음료 추가 후 가격
{
	price = p;
}

void VendingMachine::setTotal(int t) // 금액 추가
{
	total += t;
}

int main()
{
	VendingMachine V; // 이름이 V인 VendingMachine 타입의 객체 생성
	VendingMachine *p = &V;
	
	cout << "===== SWING 자판기 =====" << endl;
	cout << "1. 코카콜라 : 1500원" << endl;
	cout << "2. 비타500 : 900원" << endl;
	cout << "3. 파워에이드 : 2000원" << endl;
	cout << "4. 준비중" << endl;
	cout << "5. 계산" << endl;
	
	p->setName(V.getName());
	p->setPrice(V.getPrice());
	cout << endl;

	int num, amount;

	do
	{
		V.menu();

		cout << "번호를 선택해주세요 : ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 1500);
			break;
		case 2:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 900);
			break;
		case 3:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 2000);
			break;
		case 4:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount*V.getPrice());
			break;
		} 
	} while (num != 5);

	V.purchase(V.getTotal());
}