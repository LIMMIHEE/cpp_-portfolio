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

// 키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBIT 4 //선택 (스페이스바)

boolean isLogin = false;
CMysql* UM = new CMysql();

//함수 초기화
void gotoxy(int x, int y);
void draw_rectangle(int c, int r);
void draw_rectangle_g(int c, int r, int n, int m);
void draw_text(string p, int n, int m);

int KeyControl(); //키 컨트롤러
void titleDraw(); //타이틀
int menuDraw(); //메뉴
int loginDraw();
bool Login(); //로그인
void SignUp(); //회원가입
void Withdrawal(); //회원탈퇴

//화면이동
void Activity_Verification();
void Check_More_Detail();
void Information_input();
void the_whole_project();

////////////////////////////////////main//////////////////////////////////////////////////////
int main() {

	titleDraw(); // 타이틀

	//Activity_Verification();
	//Check_More_Detail();
	//Information_input();
	//the_whole_project();

	int loginchoice = loginDraw();
	while (true) {
		loginchoice = loginDraw();
		switch (loginchoice) {		
		case 0: //회원가입
			system("cls");
			SignUp();
			system("cls");
			break;
		case 1: //로그인
			system("cls");
			if (Login()) {
				system("cls");
				isLogin = true;
			}
			else
				loginDraw();
			break;

		case 2: //회원탈퇴
			system("cls");
			Withdrawal();
			break;
		case 3:
			system("cls");
			exit(0);
			break;
		}


		if (isLogin) {
			int menu = menuDraw(); // 메뉴

			switch (menu) {
			case 0: //일정 추가
				system("cls");
				the_whole_project();
				break;
			case 1: //일정 확인
				system("cls");
				Check_More_Detail();
				break;
			case 2: //현재 일정 추가
				system("cls");
				Information_input();
				break;
			case 3: //종료하기
				system("cls");
				exit(0);
				break;

			}
		}

	}


	system("pause>null");
	return 0;
}

///////////////////////////////////////////////함수 재정의///////////////////////////////////////////////////

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
	cout << " 일정 추가";
	gotoxy(x, y + 1); //(80,21)
	cout << " 일정 보기";
	gotoxy(x, y + 2); //(80,22)
	cout << " 현재 일정 추가";
	gotoxy(x, y + 3); //(80,23)
	cout << " 종료";

	gotoxy(x - 2, y); //78,20
	//cout << ">"; //맨 처음 초기 화살표

	while (1) {

		int n = KeyControl(); //키보드 입력값 받아오기

		switch (n) {
		case UP: {
			if (y > 20) { //y값 이동 제어
				gotoxy(x - 2, y);
				cout << " "; //현재 위치 지우기
				gotoxy(x - 2, --y);//새로 이동한 위치로 이동하여
				cout << ">"; //다시 그리기
			}

			break;
		}

		case DOWN: { //y값 이동 제어
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
	cout << " 회원가입";

	gotoxy(x, y + 1); //(80,21)
	cout << " 로그인";

	gotoxy(x, y + 2); //(80,21)
	cout << " 회원탈퇴";

	gotoxy(x, y + 3); //(80,21)
	cout << " 종료";

	gotoxy(x - 2, y); //78,20
	//cout << ">"; //맨 처음 초기 화살표

	while (1) {

		int n = KeyControl(); //키보드 입력값 받아오기

		switch (n) {
		case UP: {
			if (y > 20) { //y값 이동 제어
				gotoxy(x - 2, y);
				cout << " "; //현재 위치 지우기
				gotoxy(x - 2, --y);//새로 이동한 위치로 이동하여
				cout << ">"; //다시 그리기
			}

			break;
		}

		case DOWN: { //y값 이동 제어
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

int KeyControl() { //키 입력받아서 화살표 키에 따라 #define 값 리턴

	int chr = _getch();

	//if (chr == 0 || chr == 0xe0) {
	chr = _getch();

	if (chr == 72) { //상
		return UP;
	}
	else if (chr == 80) { //하
		return DOWN;
	}
	else if (chr == 75) { //좌
		return LEFT;
	}
	else if (chr == 77) { //우
		return RIGHT;
	}
	else if (chr == 32 || chr == 13) { //스페이스바
		return SUBIT;
	}

}

//공모전 프로젝트 세미나 등 일정 확인 칸 (현재 칸)
void Activity_Verification() {
	// 이벤트 종류( 세미나, 공모전 등등 )
	string event_kind = "   ";
	//행사 이름
	string e_name = "   ";
	// 중요도 ( 별 그거 )
	string Importance = "aaa";

	// 현재 선택한 거 X 좌표 찍어주는 거
	int selet_X_ = 61;

	draw_rectangle(15, 1);
	printf("\n");
	gotoxy(85, 3);
	printf("이전으로 돌아가기");
	gotoxy(111, 3);
	printf("홈으로 돌아가기");
	int  AllEventY = 8;
	draw_rectangle_g(125, 40, 2, 5);
	draw_text(" 현재 일정", 63, 5);
	for (int j = 0; j < 4; j++) {
		draw_text(e_name, 6, AllEventY);
		draw_text(e_name, 22, AllEventY);
		draw_text(Importance, 40, AllEventY);
		draw_text("◁", selet_X_, AllEventY);
		AllEventY += 2;
	}


	gotoxy(1, 65);
	printf(" ");
}

//자세확인
void Check_More_Detail() {
	//event_name = 프로젝트 이름
	//event_star == 중요도
	//event_info == 간단내용
	//event_info_def==상세내용

	draw_rectangle(15, 2);

	draw_rectangle(36, 7);
	draw_rectangle(76, 28);

	draw_rectangle_g(12, 2, 40, 1);

	gotoxy(114, 2);
	cout << ("이전으로 돌아가기");
	gotoxy(137, 2);
	cout << ("홈으로 돌아가기");

	draw_text(event_name, 3, 2);
	draw_text(event_star, 41, 2);
	draw_text(" 간단 내용", 23, 5);
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

	draw_text(" 상세 내용", 23, 14);
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

//넣을때 화면
void Information_input() {
	string name;
	char review;
	char details;
	int EventChk;
	int Importance;

	gotoxy(3, 3);
	printf("이름   : ");
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

	//입력받기
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
	while ((details = _getch()) != '\n') //24줄
	{
		if (details == 0x09) {
			printf("\n");
		}
		putchar(details);
	}

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

	int ALL_ScheduleY = 9;	// Y 
	//ALL_Schedule_Number == 전체 스케쥴 수

	for (int i = 0; i < ALL_Schedule_Number; i++) {
		gotoxy(4, ALL_ScheduleY);
		printf("■");
		gotoxy(15, ALL_ScheduleY);
		printf("프로젝트1");

		ALL_ScheduleY += 3;
	}
	gotoxy(ALL_Schedule_Number + (5 * ALL_Schedule_Number), 20);
	printf("");

}

void SignUp() {

	if (UM->Connect()) {
		if (UM->InsertUser()) 
			cout << "회원가입 완료! " << endl;

		else
			cout << "회원가입 실패! " << endl;
	}

	else
		cout << "db연동 실패!" << endl;

	system("cls");
}

bool Login() {
	if (UM->Login()) {
		cout << "로그인 완료! " << endl;
		_getch();
		system("cls");
		return true;
	}
	else {
		cout << "로그인 실패! " << endl;
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