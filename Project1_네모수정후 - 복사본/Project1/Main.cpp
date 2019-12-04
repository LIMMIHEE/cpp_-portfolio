#include <iostream>
#include <conio.h>
#include <windows.h>
#include<stdio.h>
#include<string>
#include <time.h>

#include "CMysql.h"
#include "CProjectManager.h"
#include <vector>
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
CProjectManager* CP = new CProjectManager();
//�Լ� �ʱ�ȭ
void gotoxy(int x, int y);
//void draw_rectangle(int c, int r);
void draw_rectangle_g(int c, int r, int n, int m);
void draw_text(string p, int n, int m);

int KeyControl(); //Ű ��Ʈ�ѷ�
void titleDraw(); //Ÿ��Ʋ
int menuDraw(); //�޴�
int loginDraw();
bool Login(); //�α���
void SignUp(); //ȸ������
void Check_More_Detail();

void Information_input();

////////////////////////////////////main//////////////////////////////////////////////////////
int main() {

	titleDraw(); // Ÿ��Ʋ

	//Activity_Verification();
	//Check_More_Detail();
	//Information_input();
	int loginchoice = loginDraw();

	while (loginchoice!=2) {
		isLogin = false;
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

		case 2: 
			system("cls");
			exit(0);
			break;
		}

		if (isLogin) {
			int menu = menuDraw(); // �޴�

			switch (menu) {
			case 0: //���� �߰�
				system("cls");
				Check_More_Detail();
				break;
			case 1: //���� ���� �߰�
				system("cls");
				Information_input();
				break;
			case 2: //�����ϱ�
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

/*
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
*/
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
	system("cls");
	int x = 80;
	int y = 20;

	gotoxy(x, y); //(80,20)
	cout << " ���� ���� ";
	gotoxy(x, y + 1); //(80,21)
	cout << " ���� ���� �߰� ";
	gotoxy(x, y + 2); //(80,22)
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
			if (y < 22) {
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
	system("cls");
	int x = 80;
	int y = 20;

	gotoxy(x, y); //(80,20) 
	cout << " ȸ������";

	gotoxy(x, y + 1); //(80,21)
	cout << " �α���";

	gotoxy(x, y + 2); //(80,21)
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
			if (y < 22) {
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

//�ڼ�Ȯ��
void Check_More_Detail() {
	//event_name = ������Ʈ �̸�
	//event_star == �߿䵵
	//event_info == ���ܳ���
	//event_info_def==�󼼳���


	string event_info = "aaaaaaaaa";
	string event_info_def = "aaaaaaaaa";

	gotoxy(114, 2);
	cout << ("�������� ���ư���");
	gotoxy(137, 2);
	cout << ("Ȩ���� ���ư���");

	draw_text("asdasd", 3, 2);
	draw_text("asdasd", 41, 2);
	draw_text(" ���� ����", 23, 5);
	int def_num = (event_info.length() / 71);
	int start_num = 0, end_num = 71, Y = 6;

	if (event_info.length() > 71) {
		for (int i = 1; i <= def_num; i++) {
			string sub1 = event_info.substr(start_num, end_num);
			draw_text(sub1, 3, Y);
			start_num = end_num * (i);
			if (start_num + 71 > event_info.length()) {
				Y++;
				string sub1 = event_info.substr(start_num, end_num);
				draw_text(sub1, 3, Y);
			}
			Y++;
		}
	}
	else {
		draw_text(event_info, 3, 6);
	}

	draw_text(" �� ����", 23, 14);
	def_num = (event_info_def.length() / 151);
	start_num = 0; end_num = 151; Y = 15;

	if (event_info_def.length() > 151) {
		for (int i = 1; i <= def_num; i++) {
			string sub1 = event_info_def.substr(start_num, end_num);
			draw_text(sub1, 3, Y);
			start_num = end_num * (i);
			if (start_num + 151 > event_info_def.length()) {
				Y++;
				string sub1 = event_info_def.substr(start_num, end_num);
				draw_text(sub1, 3, Y);
			}
			Y++;
		}
	}
	else {
		draw_text(event_info_def, 3, 15);
	}

	gotoxy(149, 44);
	printf("");

}

//������ ȭ��
void Information_input() {
	system("cls");

	string name;
	string review;
	string details;
	string EventChk;
	string Importance;


	gotoxy(3, 3);
	cout << "�̸�   : ";
	gotoxy(101, 3);
	cout << "�������� ���ư���";
	gotoxy(101, 5);
	cout << "�Է� �Ϸ�";
	gotoxy(123, 3);
	cout << "Ȩ���� ���ư���";
	gotoxy(3, 5);
	cout << "���̳�[1]   ������[2]   ������Ʈ[3]   : ";
	gotoxy(3, 7);
	cout << "�߿䵵   : ";
	cout << "\n\n";
	//draw_rectangle(26, 5);
	gotoxy(18, 9);
	cout << "������ �ı�/����";
	cout << "\n\n\n\n\n\n\n";
	//draw_rectangle(62, 25);
	gotoxy(22, 16);
	cout << "�� ����";
	gotoxy(80, 43);
	cout << "";

	//�Է¹ޱ�
	gotoxy(12, 3);
	std::cin >> name;

	gotoxy(43, 5);
	std::cin >> EventChk;

	gotoxy(14, 7);
	std::cin >> Importance;

	gotoxy(9, 10);
	std::cin >> review;

	gotoxy(9, 18);
	std::cin >> details;
	
	int num = UM->getNum();

	CP->InsertProject(num, name, EventChk, Importance, review, details);

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
	cout << "��й�ȣ : "; cin >> password;
	cout << "�̸� : "; cin >> name;
}