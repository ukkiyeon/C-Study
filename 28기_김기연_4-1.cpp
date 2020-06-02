#include <iostream>
#include <cstdlib> // srand() 함수와 rand() 함수 사용을 위한 헤더 파일
#include <ctime> // time() 함수 사용을 위한 헤더 파일

using namespace std;

class Random // Random 이라는 클래스 선언
{
public: // 멤버에 대한 접근 지정자, public은 모든 클래스 접근 가능 
	Random(); // 매개변수 없는 생성자
	int next(); // 멤버 함수
	int nextInRange(int x, int y); // 멤버 함수
}; // 세미콜론으로 끝남

Random::Random() // 매개변수 없는 생성자
{
	srand((unsigned)time(0)); // srand() 함수는 매개변수로 초기 시드 값을 설정 가능, time(0) 호출로 초기화, 매번 다른 시퀀스의 난수 생성
}

int Random::next() // 함수 리턴 타입, 클래스 이름, 범위 지정 연산자, 멤버 함수
{
	return rand(); // rand() 함수는 난수를 생성
}

int Random::nextInRange(int x, int y) // 함수 리턴 타입, 클래스 이름, 범위 지정 연산자, 멤버 함수와 매개변수
{
	return rand() % (y - x + 1) + x; // rand()를 3으로 나눈 나머지에 2를 더한 값 반환
}

int main()
{
	Random r; // 이름이 r인 Random 타입의 객체 생성

	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개 -- " << endl; // RAND_MAX 상수는 <cstdlib> 헤더 파일에 선언되어 있는 정수 32767
	for (int i = 0;i < 10;++i)
	{
		int n = r.next(); // Random의 멤버 함수 호출, 난수를 n에 대입
		cout << n << " ";
	}

	cout << endl << endl << "== 2에서 4까지의 랜덤 정수 10개 ==" << endl;
	for (int i = 0; i < 10;++i)
	{
		int n = r.nextInRange(2, 4); // Random의 멤버 함수 호출, 2, 3, 4 중 랜덤으로 n에 대입
		cout << n << " ";
	}

	cout << endl;
}