#include <iostream>

using namespace std;

int main()
{
	int num;
	int line;
	int i, k, m;

	do
	{
		cout << "--------�� ��� �ý���--------" << endl;
		cout << "����� ���� ����� �������ּ���." << endl;
		cout << "1. �����ﰢ��" << endl << "2. ���ﰢ��" << endl << "3. ����" << endl << "4. ������" << endl;
		cin >> num;
		cout << endl;

		switch (num)
		{
		case 1:
			cout << "�����ﰢ���� �����ϼ̽��ϴ�." << endl << "���� ������ �������ּ���." << endl;
			cin >> line;
			cout << endl;		

			for (i = line;i > 0;i--)
			{
				for (k = 0;k < i - 1;k++)
					cout << " ";

				for (m = line;m >= i; m--)
					cout << "*";

				cout << endl;
			}

			cout << endl;

			for (i = line;i > 0;i--)
			{
				for (k = 0;k < i;k++)
					cout << "*";

				cout << endl;
			}

			cout << endl;

			for (i = 0;i < line;i++)
			{
				for (k = 0;k < i;k++)
					cout << " ";

				for (m = 0;m < line - i;m++)
					cout << "*";

				cout << endl;
			}

			cout << endl;

			break;

		case 2:
			cout << "���ﰢ���� �����ϼ̽��ϴ�." << endl << "���� ������ �������ּ���." << endl;
			cin >> line;
			cout << endl;

			for (i = 0;i < line;i++)
			{
				for (k = line - 1;k > i;k--)
					cout << " ";

				for (m = 0;m < 2 * i + 1;m++)
					cout << "*";

				cout << endl;
			}

			cout << endl;

			break;

		case 3:
			cout << "���� �����ϼ̽��ϴ�." << endl;

			while (1)
			{
				cout << "Ȧ���� �Է����ּ���: ";
				cin >> line;

				if (line % 2 == 1)
				{
					cout << endl;

					for (i = 1;i < line / 2 + 1;i++)
					{
						for (k = 1;k <= i;k++)
							cout << "*";

						for (k = 1;k <= line - i * 2;k++)
							cout << " ";

						for (k = 1;k <= i;k++)
							cout << "*";

						cout << endl;
					}

					for (k = 1;k <= line;k++)
						cout << "*";

					cout << endl;

					for (i = line / 2;i > 0;i--)
					{
						for (k = 1;k <= i;k++)
							cout << "*";

						for (k = 1;k <= line - i * 2;k++)
							cout << " ";

						for (k = 1;k <= i;k++)
							cout << "*";

						cout << endl;
					}
					break;
				}

				else
					continue;
			}

			cout << endl;

			break;

		case 4:
			cout << "�����⸦ �����ϼ̽��ϴ�." << endl << "�����մϴ�." << endl;
		}
	} while (num != 4);
}