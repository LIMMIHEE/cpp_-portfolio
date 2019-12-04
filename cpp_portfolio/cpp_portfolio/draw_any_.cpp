
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
string event_info = "수퍼&하이퍼’ 현상은 4차 산업혁명 기술 적용이 활발해지면서 공간의 용도나 기능, 분류가 무의미해지는 초연결, 초지능, 초융합 공간을 말한다. 예를 들면 쇼핑, 업무, 취미활동 등 공간이 집으로 들어오는 대신 식사, 가족모임 등 주거공간의 여러 기능은 집밖으로 나가는 현상이 확산된다는 것이다. 김희정 피데스개발 연구개발(R&D)센터 소장은 “단독, 다세대주택 등 소규모 단지도 플랫폼을 이용해 대단지 아파트 못지않은 ";
string event_info_def = "그렇게, 독립출판으로 책을 만드는 작가 이새보미야와 사회적 사진가 김시동, 청년 문화기획자이자 문화협동조합 피올라 대표 김병준, 원주시립합창단 지휘자 정남규, 연극배우이면서 리지프로젝트 대표 이지현, 화가이자 아트팩토리 후 대표 윤기원 등 누구보다 원주를 사랑하고 작품 속에 원주를 고스란히 녹여내는 문화예술가들의 진솔한 이야기를 담아냈다. 또 연출가이자 극단 노뜰 대표 원영오, 인디 밴드 오빠 친구 동생의 리더 이승준, 가구디자이너 박종선, 그림책 작가이자 그림책 도시사업단 대표 이상희, 한지테마파크 큐레이터이자 전시기획팀장 이주은, 원주역사박물관장 박종수 등 지역에서 문화예술 활동을 하는 것을 자기 일로 받아들이고 묵묵하게 해내는 이들의 성실함";
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
	draw_rectangle(36, 7);
	draw_rectangle(76, 28);

	//draw_rectangle(10, 1);
	draw_rectangle_g(12, 2, 40, 1);

	gotoxy(114, 2);
	cout<<("이전으로 돌아가기");
	gotoxy(137, 2);
	printf("홈으로 돌아가기");

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
		if (i >=(151* next)) { // 여기에 문장 넘어가게 하는 거 찾기...
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

