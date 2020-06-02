#include <iostream>
#include <cstdlib> // srand() �Լ��� rand() �Լ� ����� ���� ��� ����
#include <ctime> // time() �Լ� ����� ���� ��� ����

using namespace std;

class Random // Random �̶�� Ŭ���� ����
{
public: // ����� ���� ���� ������, public�� ��� Ŭ���� ���� ���� 
	Random(); // �Ű����� ���� ������
	int next(); // ��� �Լ�
	int nextInRange(int x, int y); // ��� �Լ�
}; // �����ݷ����� ����

Random::Random() // �Ű����� ���� ������
{
	srand((unsigned)time(0)); // srand() �Լ��� �Ű������� �ʱ� �õ� ���� ���� ����, time(0) ȣ��� �ʱ�ȭ, �Ź� �ٸ� �������� ���� ����
}

int Random::next() // �Լ� ���� Ÿ��, Ŭ���� �̸�, ���� ���� ������, ��� �Լ�
{
	return rand(); // rand() �Լ��� ������ ����
}

int Random::nextInRange(int x, int y) // �Լ� ���� Ÿ��, Ŭ���� �̸�, ���� ���� ������, ��� �Լ��� �Ű�����
{
	return rand() % (y - x + 1) + x; // rand()�� 3���� ���� �������� 2�� ���� �� ��ȯ
}

int main()
{
	Random r; // �̸��� r�� Random Ÿ���� ��ü ����

	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10�� -- " << endl; // RAND_MAX ����� <cstdlib> ��� ���Ͽ� ����Ǿ� �ִ� ���� 32767
	for (int i = 0;i < 10;++i)
	{
		int n = r.next(); // Random�� ��� �Լ� ȣ��, ������ n�� ����
		cout << n << " ";
	}

	cout << endl << endl << "== 2���� 4������ ���� ���� 10�� ==" << endl;
	for (int i = 0; i < 10;++i)
	{
		int n = r.nextInRange(2, 4); // Random�� ��� �Լ� ȣ��, 2, 3, 4 �� �������� n�� ����
		cout << n << " ";
	}

	cout << endl;
}