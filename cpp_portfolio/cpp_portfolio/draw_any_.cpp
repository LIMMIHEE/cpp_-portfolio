
#include<stdio.h>
#include<iostream>
#include <conio.h>
#include <windows.h>
#include<string>
#include <time.h>
using namespace std;

using std::string;

void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void draw_rectangle(int c, int r);
void draw_rectangle_g(int c, int r, int n, int m);
void draw_text(string p, int n, int m);

//������ ������Ʈ ���̳� �� ���� Ȯ�� ĭ (���� ĭ)
void Activity_Verification() {

	draw_rectangle(15, 1);
	printf("\n");
	gotoxy(85,3);
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
	gotoxy(3, 3);
	printf("�̸�   :");
	gotoxy(101, 3);
	printf("�������� ���ư���");
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

int main() {
	//Activity_Verification();
	Check_More_Detail();
	//Information_input();
	//the_whole_project();

	return 0;
}
////////////////////////////////////////////////////
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

