
#include<stdio.h>
#include<iostream>
#include <conio.h>
#include <windows.h>
#include<string>
#include <time.h>
using namespace std;
int ALL_Schedule_Number = 3;
int info_end_X = 101;
int info_end_Y = 5;
string event_name = "�̰ž�� �̸�����";
string event_star = "�ڡڡڡ١�";
string event_info = "����&�����ۡ� ������ 4�� ������� ��� ������ Ȱ�������鼭 ������ �뵵�� ���, �з��� ���ǹ������� �ʿ���, ������, ������ ������ ���Ѵ�. ���� ��� ����, ����, ���Ȱ�� �� ������ ������ ������ ��� �Ļ�, �������� �� �ְŰ����� ���� ����� �������� ������ ������ Ȯ��ȴٴ� ���̴�. ������ �ǵ������� ��������(R&D)���� ������ ���ܵ�, �ټ������� �� �ұԸ� ������ �÷����� �̿��� ����� ����Ʈ �������� ";
string event_info_def = "�׷���, ������������ å�� ����� �۰� �̻����̾߿� ��ȸ�� ������ ��õ�, û�� ��ȭ��ȹ������ ��ȭ�������� �ǿö� ��ǥ �躴��, ���ֽø���â�� ������ ������, ���ع���̸鼭 ����������Ʈ ��ǥ ������, ȭ������ ��Ʈ���丮 �� ��ǥ ����� �� �������� ���ָ� ����ϰ� ��ǰ �ӿ� ���ָ� ������ �쿩���� ��ȭ���������� ������ �̾߱⸦ ��Ƴ´�. �� ���Ⱑ���� �ش� ��� ��ǥ ������, �ε� ��� ���� ģ�� ������ ���� �̽���, ���������̳� ������, �׸�å �۰����� �׸�å ���û���� ��ǥ �̻���, �����׸���ũ ť���������� ���ñ�ȹ���� ������, ���ֿ���ڹ����� ������ �� �������� ��ȭ���� Ȱ���� �ϴ� ���� �ڱ� �Ϸ� �޾Ƶ��̰� �����ϰ� �س��� �̵��� ������";
//�̰��� Ȯ�ο� �۾��� ��� ������ ���� �� �𸣰ڴµ� ����� 67�ΰ� �� ������ ���� ��������! ��~ �� ������ ���� ������ �� ��! ��! ����! ���ѹ� ������ 

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
	int  AllEventY = 8;
		draw_rectangle_g(125, 40, 2, 5);
		draw_text(" ���� ����", 63, 5);
		for (int j = 0; j < 4; j++) {
			draw_text(" ���̳�", 6, AllEventY);
				draw_text("  ________________", 22, AllEventY);
				draw_text("\t  �ڡڡڡ١�", 40, AllEventY);
				draw_text("\t 50%", 50, AllEventY);
				draw_text("\t ��", 61, AllEventY);
				AllEventY += 2;
		}


	gotoxy(1, 65);
	printf(" ");
}
//�ڼ�Ȯ��
void Check_More_Detail() {
	draw_rectangle(15, 2);
	

	//gotoxy(0,10);
	draw_rectangle(36, 7);
	draw_rectangle(76, 28);

	//draw_rectangle(10, 1);
	draw_rectangle_g(12, 2, 40, 1);

	gotoxy(114, 2);
	cout<<("�������� ���ư���");
	gotoxy(137, 2);
	printf("Ȩ���� ���ư���");

	draw_text(event_name, 3, 2);
	draw_text(event_star, 41, 2);
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
			start_num = end_num * (i );
			if (start_num+151 > event_info_def.length()) {
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
	/* int n_i = 0, x_p = 3; Y_next = 15;
	while (n_i < event_info_def.length()) {
		if (event_info_def[n_i] == '\n') {
			Y_next++;
			x_p = 3;
		}
		gotoxy(x_p, Y_next);
		cout << event_info_def[n_i];
		n_i++;
		x_p++;
	}
	*/
	/*
	X = 3; Y_next = 15; next = 1;
	for (int i = 0; i < event_info_def.length(); i++) {
		if (i >=(151* next)) { // ���⿡ ���� �Ѿ�� �ϴ� �� ã��...
			Y_next++;
			next++;
			X = 3;
		}
		
		gotoxy(X, Y_next);
		cout << event_info_def[i];
		X++;
	*/
	gotoxy(149, 44);
	printf("");

}
//������ ȭ��
void Information_input() {
	gotoxy(3, 3);
	printf("�̸�   :");
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
}
//��ü Ȯ��
void the_whole_project() {
	gotoxy(17, 3);
	printf("��ü ���");
	printf("\n\n\n\n\n");
	gotoxy(41, 5);
	printf("�������� ���ư���");
	gotoxy(64, 5);
	printf("Ȩ���� ���ư���");

	int ALL_ScheduleY = 9;

	for (int i = 0; i < ALL_Schedule_Number; i++) {
		gotoxy(4, ALL_ScheduleY);
		printf("��");
		gotoxy(15, ALL_ScheduleY);
		printf("������Ʈ1");

		ALL_ScheduleY += 3;
	}
	gotoxy(ALL_Schedule_Number+(5* ALL_Schedule_Number), 20);
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

