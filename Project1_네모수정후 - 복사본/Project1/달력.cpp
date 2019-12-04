#include <iostream>
using namespace std;


int main()
{
	int year;
	int month;
	int totalDay = 0;
	int i = 1990;
	int dayOfWeek; // 0 : ��, 1: ȭ, .....
	int dayOfMonth; // �ش� ���� �� �ϼ�

	cout << "�⵵ �Է� : ";
	cin >> year;
	cout << "�� �Է� : ";
	cin >> month;

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		dayOfMonth = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		dayOfMonth = 30;
		break;
	case 2:
		if ((year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0))
		{
			dayOfMonth = 29;
		}
		else
		{
			dayOfMonth = 28;
		}
		break;
	}

	cout << year << "�� " << month << "�� �޷� =====" << endl;
	cout << "�� ȭ �� �� �� �� ��" << endl;

	for (i = 0; i < totalDay % 7; i++)
	{
		cout << "   ";
	}
	for (i = 1; i <= dayOfMonth; i++)
	{
		printf("%2d ", i);

		if (totalDay % 7 == 6)
		{
			cout << endl;
		}
		totalDay++;
	}


	cout << endl << endl;


	return 0;
}
