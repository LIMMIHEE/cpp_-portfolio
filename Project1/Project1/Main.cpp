#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
using namespace std;

//consol = 180 * 45 

// Ű���� ��
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBIT 4 //���� (�����̽���)

//�Լ� �ʱ�ȭ
void gotoxy(int x, int y); //gotoxy()
int KeyControl(); //Ű ��Ʈ�ѷ�
void titleDraw(); //Ÿ��Ʋ
int menuDraw(); //�޴�
void draw_rectangle(int c, int r); //�׸� �׸���

//ȭ���̵�
void AddSchedule();
void CheckSchedule();

////////////////////////////////////main//////////////////////////////////////////////////////
int main() {
	titleDraw(); // Ÿ��Ʋ
	int menu = menuDraw(); // �޴�

	switch (menu) {
	case 0: //���� �߰�
		system("cls");
		cout << "���� �߰�" << endl;
		break;
	case 1: //���� Ȯ��
		system("cls");
		cout << "���� Ȯ��" << endl;
		break;
	case 2: //���� ���� �߰�
		system("cls");
		cout << "���� ���� �߰�" << endl;
		break;
	case 3: //�����ϱ�
		system("cls");
		exit(0);
		break;

	}


	system("pause>null");
	return 0;
}

///////////////////////////////////////////////�Լ� ������///////////////////////////////////////////////////

void titleDraw() {
	gotoxy(80, 10);
	cout << "Memo My Prject" << endl;
}

int menuDraw() {

	int x = 80;
	int y = 20;

	gotoxy(x, y); //(80,20)
	cout << " ���� �߰�";
	gotoxy(x, y + 1); //(80,21)
	cout << " ���� ����";
	gotoxy(x, y + 2); //(80,22)
	cout << " ���� ���� �߰�";
	gotoxy(x, y + 3); //(80,23)
	cout << " ����";

	gotoxy(x - 2, y); //78,20
	//cout << ">"; //�� ó�� �ʱ� ȭ��ǥ

	while (1) {

		int n = KeyControl(); //Ű���� �Է°� �޾ƿ���

		switch (n) {
		case UP: {
			if (y > 20) { //y�� �̵� ����
				gotoxy(x - 2, y);
				cout << " "; //���� ��ġ �����
				gotoxy(x - 2, --y);//���� �̵��� ��ġ�� �̵��Ͽ�
				cout << ">"; //�ٽ� �׸���
			}

			break;
		}

		case DOWN: { //y�� �̵� ����
			if (y < 23) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}

		case SUBIT: {
			return y - 20;
			break;
		}

		}
	}

}

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int KeyControl() { //Ű �Է¹޾Ƽ� ȭ��ǥ Ű�� ���� #define �� ����

	int chr = _getch();

	//if (chr == 0 || chr == 0xe0) {
	chr = _getch();
	if (chr == 72) { //��
		return UP;
	}
	else if (chr == 80) { //��
		return DOWN;
	}
	else if (chr == 75) { //��
		return LEFT;
	}
	else if (chr == 77) { //��
		return RIGHT;
	}
	else if (chr == 32 || chr == 13) { //�����̽���
		return SUBIT;
	}
	//}
}

void AddSchedule()
{
	//�Է¹ޱ�
	//database�� �ֱ�
}

void CheckSchedule()
{
	//����ϱ�
}