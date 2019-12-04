#include <iostream>
#include <conio.h>
#include <windows.h>
#include<stdio.h>
#include<string>
#include <time.h>

#include "CUser.h"
#include "CMysql.h"
using namespace std;

//consol = 180 * 45 

// Ű���� ��
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBIT 4 //���� (�����̽���)

boolean isLogin = false;
CMysql* UM = new CMysql();

//�Լ� �ʱ�ȭ
void gotoxy(int x, int y);
void draw_rectangle(int c, int r);
void draw_rectangle_g(int c, int r, int n, int m);
void draw_text(string p, int n, int m);

int KeyControl(); //Ű ��Ʈ�ѷ�
void titleDraw(); //Ÿ��Ʋ
int menuDraw(); //�޴�
int loginDraw();
bool Login(); //�α���
void SignUp(); //ȸ������
void Withdrawal(); //ȸ��Ż��

//ȭ���̵�
void Activity_Verification();
void Check_More_Detail();
void Information_input();
void the_whole_project();

////////////////////////////////////main//////////////////////////////////////////////////////
int main() {

	titleDraw(); // Ÿ��Ʋ

	//Activity_Verification();
	//Check_More_Detail();
	//Information_input();
	//the_whole_project();

	int loginchoice = loginDraw();
	while (true) {
		loginchoice = loginDraw();
		switch (loginchoice) {		
		case 0: //ȸ������
			system("cls");
			SignUp();
			system("cls");
			break;
		case 1: //�α���
			system("cls");
			if (Login()) {
				system("cls");
				isLogin = true;
			}
			else
				loginDraw();
			break;

		case 2: //ȸ��Ż��
			system("cls");
			Withdrawal();
			break;
		case 3:
			system("cls");
			exit(0);
			break;
		}


		if (isLogin) {
			int menu = menuDraw(); // �޴�

			switch (menu) {
			case 0: //���� �߰�
				system("cls");
				the_whole_project();
				break;
			case 1: //���� Ȯ��
				system("cls");
				Check_More_Detail();
				break;
			case 2: //���� ���� �߰�
				system("cls");
				Information_input();
				break;
			case 3: //�����ϱ�
				system("cls");
				exit(0);
				break;

			}
		}

	}


	system("pause>null");
	return 0;
}

///////////////////////////////////////////////�Լ� ������///////////////////////////////////////////////////

void draw_rectangle(int c, int r) {
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (int i = 1; i < 7; i++) {
		b[i] = 0xa0 + i;
	}

	printf("%c%c ", a, b[3]);
	for (int i = 0; i < c; i++) {
		printf("%c%c ", a, b[1]);
	}
	printf("%c%c\n", a, b[4]);

	for (int i = 0; i < r; i++) {
		printf("%c%c ", a, b[2]);
		for (int j = 0; j < c; j++) {
			printf("  ");
		}
		printf("%c%c\n", a, b[2]);
	}
	printf("%c%c ", a, b[6]);
	for (int i = 0; i < c; i++) {
		printf("%c%c ", a, b[1]);
	}
	printf("%c%c\n", a, b[5]);
}
/////////////////////////////////////////////////////////////
void draw_rectangle_g(int c, int r, int n, int m) {
	int setN = n;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (int i = 1; i < 7; i++) {
		b[i] = 0xa0 + i;
	}
	gotoxy(n - 1, m);
	printf("%c%c ", a, b[3]);
	for (int i = 0; i < c; i++) {
		gotoxy(n++, m);
		printf("%c%c ", a, b[1]);
	}

	gotoxy(n, m++);
	printf("%c%c", a, b[4]);
	n = setN - 1;
	for (int i = 0; i < r; i++) {
		gotoxy(n++, m);
		printf("%c%c ", a, b[2]);
		for (int j = 0; j < c; j++) {
			gotoxy(n++, m);
			printf("  ");
		}
		gotoxy(n++, m++);
		printf("%c%c", a, b[2]);
		n = setN - 1;
	}

	gotoxy(n, m);
	printf("%c%c ", a, b[6]);
	n = setN;
	for (int i = 0; i < c; i++) {
		gotoxy(n++, m);
		printf("%c%c ", a, b[1]);
	}
	gotoxy(n++, m++);
	printf("%c%c", a, b[5]);
}
//////////////////////////////////////////////////////
void draw_text(string p, int n, int m) {
	gotoxy(n, m);
	cout << p;
}

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

int loginDraw() {

	int x = 80;
	int y = 20;

	gotoxy(x, y); //(80,20) 
	cout << " ȸ������";

	gotoxy(x, y + 1); //(80,21)
	cout << " �α���";

	gotoxy(x, y + 2); //(80,21)
	cout << " ȸ��Ż��";

	gotoxy(x, y + 3); //(80,21)
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

}

//������ ������Ʈ ���̳� �� ���� Ȯ�� ĭ (���� ĭ)
void Activity_Verification() {

	draw_rectangle(15, 1);
	printf("\n");
	gotoxy(85, 3);
	printf("�������� ���ư���");
	gotoxy(111, 3);
	printf("Ȩ���� ���ư���");
	draw_rectangle_g(125, 10, 2, 5);
	draw_text(" ���̳�", 63, 5);
	draw_text("  ________________", 6, 8);
	draw_text("\t  �ڡڡڡ١�", 22, 8);
	draw_text("\t 50%", 40, 8);
	draw_text("\t ��", 41, 8);
	draw_text("  ________________", 6, 10);
	draw_text("\t  �ڡڡ١١�", 22, 10);
	draw_text("\t 50%", 40, 10);
	draw_text("  ________________", 6, 12);
	draw_text("\t  �ڡ١١١�", 22, 12);
	draw_text("\t 50%", 40, 12);

	draw_rectangle_g(125, 10, 2, 17);
	draw_text(" ������", 63, 17);
	draw_text("  ________________", 6, 20);
	draw_text("\t  �ڡڡڡ١�", 22, 20);
	draw_text("\t 50%", 40, 20);
	draw_text("  ________________", 6, 22);
	draw_text("\t  �ڡڡ١١�", 22, 22);
	draw_text("\t 50%", 40, 22);
	draw_text("  ________________", 6, 24);
	draw_text("\t  �ڡ١١١�", 22, 24);
	draw_text("\t 50%", 40, 24);

	draw_rectangle_g(125, 10, 2, 29);

	draw_text(" ������Ʈ", 63, 29);
	draw_text("  ________________", 6, 32);
	draw_text("\t  �ڡڡڡ١�", 22, 32);
	draw_text("\t 50%", 40, 32);
	draw_text("  ________________", 6, 34);
	draw_text("\t  �ڡڡ١١�", 22, 34);
	draw_text("\t 50%", 40, 34);
	draw_text("  ________________", 6, 36);
	draw_text("\t  �ڡ١١١�", 22, 36);
	draw_text("\t 50%", 40, 36);


	gotoxy(1, 40);
	printf(" ");


}

//�ڼ�Ȯ��
void Check_More_Detail() {
	draw_rectangle(15, 2);

	//gotoxy(0,10);
	draw_rectangle(35, 7);
	draw_rectangle(75, 28);

	//draw_rectangle(10, 1);
	draw_rectangle_g(10, 2, 40, 1);
	draw_rectangle_g(10, 2, 50, 1);

	gotoxy(114, 2);
	printf("�������� ���ư���");
	gotoxy(137, 2);
	printf("Ȩ���� ���ư���");

	gotoxy(149, 44);
	printf("");

}

//������ ȭ��
void Information_input() {
	string name;
	char review;
	char details;
	int EventChk;
	int Importance;

	gotoxy(3, 3);
	printf("�̸�   : ");
	gotoxy(101, 3);
	printf("�������� ���ư���");
	gotoxy(101, 5);
	printf("�Է� �Ϸ�");
	gotoxy(123, 3);
	printf("Ȩ���� ���ư���");
	gotoxy(3, 5);
	printf("���̳�[1]   ������[2]   ������Ʈ[3]   : ");
	gotoxy(3, 7);
	printf("�߿䵵   : ");
	printf("\n\n");
	draw_rectangle(26, 5);
	gotoxy(18, 9);
	printf("������ �ı�/����");
	printf("\n\n\n\n\n\n\n");
	draw_rectangle(62, 25);
	gotoxy(22, 16);
	printf("�� ����");
	gotoxy(80, 43);
	printf("");

	//�Է¹ޱ�
	gotoxy(12, 3);
	cin >> name;

	gotoxy(43, 5);
	cin >> EventChk;

	gotoxy(14, 7);
	cin >> Importance;

	gotoxy(9, 10);

	int y = 10;
	while ((review = _getch()) != '\r')
	{
		if (review == 0x09) {
			y += 1;
			gotoxy(1, y);
		}
		putchar(review);
	}

	gotoxy(9, 18);
	while ((details = _getch()) != '\n') //24��
	{
		if (details == 0x09) {
			printf("\n");
		}
		putchar(details);
	}

}

//��ü Ȯ��
void the_whole_project() {
	gotoxy(17, 3);
	printf("��ü ������Ʈ");
	printf("\n\n\n\n\n");
	gotoxy(41, 5);
	printf("�������� ���ư���");
	gotoxy(64, 5);
	printf("Ȩ���� ���ư���");

	gotoxy(4, 9);
	printf("��");
	gotoxy(15, 9);
	printf("������Ʈ1");

	gotoxy(4, 12);
	printf("��");
	gotoxy(15, 12);
	printf("������Ʈ2");

	gotoxy(40, 20);
	printf("");

}

void SignUp() {

	if (UM->Connect()) {
		if (UM->InsertUser()) 
			cout << "ȸ������ �Ϸ�! " << endl;

		else
			cout << "ȸ������ ����! " << endl;
	}

	else
		cout << "db���� ����!" << endl;

	system("cls");
}

bool Login() {
	if (UM->Login()) {
		cout << "�α��� �Ϸ�! " << endl;
		_getch();
		system("cls");
		return true;
	}
	else {
		cout << "�α��� ����! " << endl;
		_getch();
		system("cls");
		return false;
	}
}

void Withdrawal() {
	char name[20];
	char password[20];
	cout << "Password : "; cin >> password;
	cout << "Name : "; cin >> name;
}