#include <iostream>

using namespace std;

int main()
{
	int num;
	int line;
	int i, k, m;

	do
	{
		cout << "--------별 찍기 시스템--------" << endl;
		cout << "만들고 싶은 모양을 선택해주세요." << endl;
		cout << "1. 직각삼각형" << endl << "2. 정삼각형" << endl << "3. 나비" << endl << "4. 나가기" << endl;
		cin >> num;
		cout << endl;

		switch (num)
		{
		case 1:
			cout << "직각삼각형을 선택하셨습니다." << endl << "행의 개수를 선택해주세요." << endl;
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
			cout << "정삼각형을 선택하셨습니다." << endl << "행의 개수를 선택해주세요." << endl;
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
			cout << "나비를 선택하셨습니다." << endl;

			while (1)
			{
				cout << "홀수를 입력해주세요: ";
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
			cout << "나가기를 선택하셨습니다." << endl << "감사합니다." << endl;
		}
	} while (num != 4);
}