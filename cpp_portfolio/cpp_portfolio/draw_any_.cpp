
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

//공모전 프로젝트 세미나 등 일정 확인 칸 (현재 칸)
void Activity_Verification() {

	draw_rectangle(15, 1);
	printf("\n");
	gotoxy(85,3);
	printf("이전으로 돌아가기");
	gotoxy(111, 3);
	printf("홈으로 돌아가기");
	draw_rectangle_g(125, 10, 2, 5);
	draw_text(" 세미나", 63, 5);
	draw_text("  ________________", 6, 8);
	draw_text("\t  ★★★☆☆", 22, 8);
	draw_text("\t 50%", 40, 8);
	draw_text("\t ◁", 41, 8);
	draw_text("  ________________", 6, 10);
	draw_text("\t  ★★☆☆☆", 22, 10);
	draw_text("\t 50%", 40, 10);
	draw_text("  ________________", 6, 12);
	draw_text("\t  ★☆☆☆☆", 22, 12);
	draw_text("\t 50%", 40, 12);

	draw_rectangle_g(125, 10, 2, 17);
	draw_text(" 공모전", 63, 17);
	draw_text("  ________________", 6, 20);
	draw_text("\t  ★★★☆☆", 22, 20);
	draw_text("\t 50%", 40, 20);
	draw_text("  ________________", 6, 22);
	draw_text("\t  ★★☆☆☆", 22, 22);
	draw_text("\t 50%", 40, 22);
	draw_text("  ________________", 6, 24);
	draw_text("\t  ★☆☆☆☆", 22, 24);
	draw_text("\t 50%", 40, 24);

	draw_rectangle_g(125, 10, 2, 29);

	draw_text(" 프로젝트", 63, 29);
	draw_text("  ________________", 6, 32);
	draw_text("\t  ★★★☆☆", 22, 32);
	draw_text("\t 50%", 40, 32);
	draw_text("  ________________", 6, 34);
	draw_text("\t  ★★☆☆☆", 22, 34);
	draw_text("\t 50%", 40, 34);
	draw_text("  ________________", 6, 36);
	draw_text("\t  ★☆☆☆☆", 22, 36);
	draw_text("\t 50%", 40, 36);


	gotoxy(1, 40);
	printf(" ");


}
//자세확인
void Check_More_Detail() {
	draw_rectangle(15, 2);

	//gotoxy(0,10);
	draw_rectangle(35, 7);
	draw_rectangle(75, 28);

	//draw_rectangle(10, 1);
	draw_rectangle_g(10, 2, 40, 1);
	draw_rectangle_g(10, 2, 50, 1);

	gotoxy(114, 2);
	printf("이전으로 돌아가기");
	gotoxy(137, 2);
	printf("홈으로 돌아가기");

	gotoxy(149, 44);
	printf("");

}
//넣을때 화면
void Information_input() {
	gotoxy(3, 3);
	printf("이름   :");
	gotoxy(101, 3);
	printf("이전으로 돌아가기");
	gotoxy(123, 3);
	printf("홈으로 돌아가기");

	gotoxy(3, 5);
	printf("세미나[1]   공모전[2]   프로젝트[3]   : ");
	gotoxy(3, 7);
	printf("중요도   : ");
	printf("\n\n");
	draw_rectangle(26, 5);
	gotoxy(18, 9);
	printf("간단한 후기/내용");
	printf("\n\n\n\n\n\n\n");
	draw_rectangle(62, 25);
	gotoxy(22, 16);
	printf("상세 내용");
	gotoxy(80, 43);
	printf("");
}
//전체 확인
void the_whole_project() {
	gotoxy(17, 3);
	printf("전체 프로젝트");
	printf("\n\n\n\n\n");
	gotoxy(41, 5);
	printf("이전으로 돌아가기");
	gotoxy(64, 5);
	printf("홈으로 돌아가기");

	gotoxy(4, 9);
	printf("■");
	gotoxy(15, 9);
	printf("프로젝트1");

	gotoxy(4, 12);
	printf("■");
	gotoxy(15, 12);
	printf("프로젝트2");

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

