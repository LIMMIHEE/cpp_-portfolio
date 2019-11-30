#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
using namespace std;

//consol = 180 * 45 

// 키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBIT 4 //선택 (스페이스바)

//함수 초기화
void gotoxy(int x, int y); //gotoxy()
int KeyControl(); //키 컨트롤러
void titleDraw(); //타이틀
int menuDraw(); //메뉴
void draw_rectangle(int c, int r); //네모 그리기

//화면이동
void AddSchedule();
void CheckSchedule();

////////////////////////////////////main//////////////////////////////////////////////////////
int main() {
	titleDraw(); // 타이틀
	int menu = menuDraw(); // 메뉴

	switch (menu) {
	case 0: //일정 추가
		system("cls");
		cout << "일정 추가" << endl;
		break;
	case 1: //일정 확인
		system("cls");
		cout << "일정 확인" << endl;
		break;
	case 2: //현재 일정 추가
		system("cls");
		cout << "현재 일정 추가" << endl;
		break;
	case 3: //종료하기
		system("cls");
		exit(0);
		break;

	}


	system("pause>null");
	return 0;
}

///////////////////////////////////////////////함수 재정의///////////////////////////////////////////////////

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
	//}
}

void AddSchedule()
{
	//입력받기
	//database에 넣기
}

void CheckSchedule()
{
	//출력하기
}