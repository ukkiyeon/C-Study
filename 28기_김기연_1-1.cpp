#include <iostream> //��ó���⿡ ������ ����
#include <string> //<string> ��� ���Ϸ� ����
using namespace std; //std namespace ����

int main() {
	char name[50];
	cout << "�̸��� �Է��ϼ���: "; 
	cin.getline(name, 50); //������ �ִ� ���ڿ� �Է� ����
	string birth; //���ڿ� ũ�� ����X, ���� �ν� ����
	cout << "������ �Է��ϼ���: ";
	getline(cin, birth);
	int num;
	cout << "���̸� �Է��ϼ���: ";
	cin >> num;
	char major[30];
	cout << "�Ҽ� �а��� �Է��ϼ���: ";
	cin >> major;
	getchar(); //cin�� \n�� �Է¹���
	char hobby[40];
	cout << "��̸� �Է��ϼ���: ";
	cin.getline(hobby, 40);
	
	cout << endl << "========================================" << endl;
	cout << "<ȸ�� ����>" << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << birth << endl;
	cout << "����: " << num << endl;
	cout << "�Ҽ� �а�: " << major << endl;
	cout << "���: " << hobby << endl;
}
