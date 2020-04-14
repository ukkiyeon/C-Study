#include <iostream> //전처리기에 내리는 지시
#include <string> //<string> 헤더 파일로 선언
using namespace std; //std namespace 생략

int main() {
	char name[50];
	cout << "이름을 입력하세요: "; 
	cin.getline(name, 50); //공백이 있는 문자열 입력 가능
	string birth; //문자열 크기 제약X, 공백 인식 가능
	cout << "생일을 입력하세요: ";
	getline(cin, birth);
	int num;
	cout << "나이를 입력하세요: ";
	cin >> num;
	char major[30];
	cout << "소속 학과를 입력하세요: ";
	cin >> major;
	getchar(); //cin의 \n을 입력받음
	char hobby[40];
	cout << "취미를 입력하세요: ";
	cin.getline(hobby, 40);
	
	cout << endl << "========================================" << endl;
	cout << "<회원 정보>" << endl;
	cout << "이름: " << name << endl;
	cout << "생일: " << birth << endl;
	cout << "나이: " << num << endl;
	cout << "소속 학과: " << major << endl;
	cout << "취미: " << hobby << endl;
}
