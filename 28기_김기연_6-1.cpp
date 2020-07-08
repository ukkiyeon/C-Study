#include <iostream>
#include <string>

using namespace std;

class ATM
{
private:
	string name; // 계좌주 이름
	int pw; // 계좌 비밀번호
	int money; // 계좌 잔액
	
public:
	ATM(); //생성자
	void deposit(); // 1. 입금
	void withdraw(); // 2. 인출
	void send(string receiver, int sendMon); // 3. 이체-받음
	void receive(int receiveMon); // 3. 이체-보냄
	int getMoney(); // 4. 얼마있는지 출력
	string getName(); // 이름 불러오기

	void setName(); // 계좌주 이름 입력
	void setPW(); // 계좌 비밀번호 입력
	void checkPW(); // 계좌 비밀번호 입력 확인
	void setMoney(); // 계좌 잔액 입력
};




ATM::ATM()
{}

void ATM::deposit() // 1. 입금 
{
	int deposit_price;

	cout << "입금할 금액을 입력해주세요 >> ";
	cin >> deposit_price;
	money = money + deposit_price;
	cout << endl << "현재 " << name << "님의 잔액은 " << money << "원 입니다." << endl;
}

void ATM::withdraw() // 2. 인출 
{
	int withdraw_price; 
	int withdraw_pw; 

	cout << "얼마를 인출하시겠습니까? >> ";
	cin >> withdraw_price;
	
	while (1)
	{
		cout << "비밀번호를 입력해주세요 >> ";
		cin >> withdraw_pw;

		if (pw != withdraw_pw) // 비밀번호가 다르면
		{
			cout << "비밀번호가 틀렸습니다.";
			continue; // 재입력
		}

		else // 비밀번호가 맞으면
		{
			money = money - withdraw_price;
			cout << endl << "현재 " << name << "님의 잔액은 " << money << "원 입니다." << endl;
			break;
		}
	}
}

void ATM::send(string receiver, int sendMon) // 3. 이체-받음
{
	money = money - sendMon;
}

void ATM::receive(int receiverMon) // 3. 이체-보냄
{	
	money = money + receiverMon;
}

int ATM::getMoney() // 4. 얼마있는지 출력
{
	return money;
}

string ATM::getName() // 이름 불러오기
{
	return name;
}

void ATM::setName() // 계좌주 이름 입력
{
	cin >> name;
}

void ATM::setPW() // 계좌 비밀번호 입력
{
	cin >> pw;
}

void ATM::checkPW() // 계좌 비밀번호 입력 확인
{
	int checkpw; // 비밀번호 재입력 변수

	cin >> checkpw;

	if (checkpw != pw) // 둘이 다르면
	{
		do
		{
			cout << "비밀번호가 서로 다릅니다." << endl << endl;
			cout << "비밀번호를 입력해 주세요 >> ";
			cin >> checkpw;
		} while (checkpw != pw); // 같을 때까지 반복
	}
}

void ATM::setMoney() // 계좌 잔액 입력
{
	cin >> money;
}




int main() 
{
	int cnt; // 은행 가입 인원 수
	string name;
	string receiver;
	int pw;
	int money;
	int i; // 반복문
	int k;
	int m;
	int num;
	int sendMon;

	cout << "은행에 가입할 인원을 입력해주세요 >> ";
	cin >> cnt;

	ATM *p = new ATM[cnt]; // cnt 입력한 값만큼 객체 배열 동적 생성

	for (i = 0;i < cnt;i++)
	{
		cout << endl << i + 1 << "번째 손님" << endl << endl;
		cout << "성명을 적어주십시오 >> ";
		(p + i)->setName(); // 계좌주 이름 입력
		cout << "비밀번호를 입력해주세요 >> ";
		(p + i)->setPW(); // 계좌 비밀번호 입력		
		cout << "한 번 더 입력해주세요 >> ";
		(p + i)->checkPW(); // 계좌 비밀번호 입력 확인
		cout << "입금할 금액을 입력해주세요 >> ";
		(p + i)->setMoney(); // 계좌 잔액 입력
		cout << endl << endl; 
	}

	while (1)
	{
		do
		{
			cout << endl << "--- SWING ATM ---" << endl;
			cout << "성함을 입력해주세요 (종료라면 X를 입력해주세요) >> ";
			cin >> name;

			k = 10;

			for (i = 0;i < cnt;i++)
			{
				if (name == (p + i)->getName()) // 만약 name과 getName()으로 불러온 이름이 같으면
					k = i; // i를 k에 대입
			}

			if (k == 10 && name != "X") // 만약 k가 10이고 name도 X가 아니면
				cout << "존재하지 않는 계좌주입니다." << endl;

			else
				break;
		} while (name != "X"); // name에 X가 입력되면 반복문 탈출

		if (name == "X") // while문도 탈출, 프로그램이 종료됨
		{
			cout << "ATM을 종료합니다." << endl;
			break;
		}
			
		do
		{
			cout << endl << "--- SWING ATM " << (p + k)->getName() << "님" << "---" << endl; // 위에서 받은 이름
			cout << "1. 입금" << endl << "2. 인출" << endl << "3. 이체" << endl << "4. 잔액 확인" << endl << "5. 종료" << endl;
			cout << endl << "번호를 선택해주세요 >> ";
			cin >> num;

			switch (num)
			{
			case 1:
				(p + k)->deposit();
				break;

			case 2:
				(p + k)->withdraw();
				break;

			case 3:
				cout << "누구에게 보내겠습니까? >> ";
				cin >> receiver;

				m = 10;

				for (i = 0;i < cnt;i++)
				{
					if (receiver == (p + i)->getName())
						m = i;
				}

				if (m == 10)
					break;

				cout << "얼마를 보내겠습니까? >> ";
				cin >> sendMon;
				(p + k)->send((p + m)->getName(), sendMon);

				while (1)
				{
					cout << "비밀번호를 입력해주세요 >> ";
					cin >> pw;

					if (pw != pw)
					{
						cout << "비밀번호가 틀렸습니다. ";
						continue;
					}

					else
					{
						cout << endl << receiver << "님께 " << sendMon << "원을 보냈습니다." << endl;
						(p + m)->receive(sendMon);
						cout << endl << "현재 " << (p + k)->getName() << "님의 잔액은 " << (p + k)->getMoney() << "원 입니다." << endl;
						break;
					}	
				}
				break;

			case 4:
				cout << (p + k)->getName() << "님의 현재 잔액은 " << (p+k)->getMoney() << "원 입니다." << endl;
				break;

			case 5:
				break;
			}
		} while (num != 5);
	}
}
