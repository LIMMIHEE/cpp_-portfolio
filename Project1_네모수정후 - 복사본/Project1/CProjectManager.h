#include <iostream>
#include <string>
using namespace std;

class CProjectManager
{
public:
	string filepath;

	string event_name; //프로젝트 이름
	string event_chk;
	string event_star; // 중요도
	string event_info;  // 간단내용
	string event_info_def; //상세내용

	bool InsertProject(int num, string event_name, string event_chk, string event_star, string event_info, string ecnet_info_def);

	CProjectManager(string filepath);
	CProjectManager();
	~CProjectManager();
};
