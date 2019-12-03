
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
string event_name = "이거어언 이르으음";
string event_star = "★★★☆☆";
string event_info = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa가나다랍마감작맞ㄱㅁㅈㄱ";
string event_info_def = "이것은 확인용 글씨고 어떻게 될지는 나도 잘 모르겠는데 영어는 67인가 나 나나나 난나 나나난나! 하~ 난 나나나 난난 나나나 난 나! 하! 문장! ㅎ한번 오지aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaㅁㅁㅁㅁㅁㅁ";
//이것은 확인용 글씨고 어떻게 될지는 나도 잘 모르겠는데 영어는 67인가 나 나나나 난나 나나난나! 하~ 난 나나나 난난 나나나 난 나! 하! 문장! ㅎ한번 오지게 

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
	int  AllEventY = 8;
		draw_rectangle_g(125, 40, 2, 5);
		draw_text(" 현재 일정", 63, 5);
		for (int j = 0; j < 4; j++) {
			draw_text(" 세미나", 6, AllEventY);
				draw_text("  ________________", 22, AllEventY);
				draw_text("\t  ★★★☆☆", 40, AllEventY);
				draw_text("\t 50%", 50, AllEventY);
				draw_text("\t ◁", 61, AllEventY);
				AllEventY += 2;
		}


	gotoxy(1, 65);
	printf(" ");
}
//자세확인
void Check_More_Detail() {
	draw_rectangle(15, 2);
	

	//gotoxy(0,10);
	draw_rectangle(35, 7);
	draw_rectangle(75, 28);

	//draw_rectangle(10, 1);
	draw_rectangle_g(12, 2, 40, 1);

	gotoxy(114, 2);
	printf("이전으로 돌아가기");
	gotoxy(137, 2);
	printf("홈으로 돌아가기");

	draw_text(event_name, 3, 2);
	draw_text(event_star, 41, 2);
	draw_text(" 간단 내용", 23, 5);
	int info_num = (event_info.length() / 71) + 1;
	int start_num = 0, end_num = 71, Y = 6;
	if (event_info.length() > 71) {
		for (int i = 1; i <= info_num; i++) {
			string sub1 = event_info.substr(start_num, end_num);
			draw_text(sub1, 3, Y);
			start_num = end_num;
			if (info_num - 1 == i ) {
				end_num = event_info.length();
			}
			else {
				end_num = end_num * i - 1;
			}
			Y++;
		}
	}
	else {
		draw_text(event_info, 3, 6);
	}
	
	
	draw_text(" 상세 내용", 23, 14);
	int def_num= (event_info_def.length()/151)+1;
	start_num = 0 , end_num=151,Y=15;
	
	if (event_info_def.length() > 151) {
		for (int i = 1; i <= def_num; i++) {
			if (i >= 2) {
				start_num -= 1;
			}
			string sub1 = event_info_def.substr(start_num, end_num);
			draw_text(sub1, 3, Y);
			start_num = end_num;
			if (def_num == i - 1) {
				end_num = event_info_def.length();
			}
			else {
				end_num = end_num * i -1;
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
//넣을때 화면
void Information_input() {
	gotoxy(3, 3);
	printf("이름   :");
	gotoxy(101, 3);
	printf("이전으로 돌아가기");
	gotoxy(101, 5);
	printf("입력 완료");
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
	printf("전체 행사");
	printf("\n\n\n\n\n");
	gotoxy(41, 5);
	printf("이전으로 돌아가기");
	gotoxy(64, 5);
	printf("홈으로 돌아가기");

	int ALL_ScheduleY = 9;

	for (int i = 0; i < ALL_Schedule_Number; i++) {
		gotoxy(4, ALL_ScheduleY);
		printf("■");
		gotoxy(15, ALL_ScheduleY);
		printf("프로젝트1");

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

