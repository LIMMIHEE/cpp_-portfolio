#include <iostream>
#include <string>
using namespace std;

class CProjectManager
{
public:
	string filepath;

	string event_name; //������Ʈ �̸�
	string event_chk;
	string event_star; // �߿䵵
	string event_info;  // ���ܳ���
	string event_info_def; //�󼼳���

	bool InsertProject(int num, string event_name, string event_chk, string event_star, string event_info, string ecnet_info_def);

	CProjectManager(string filepath);
	CProjectManager();
	~CProjectManager();
};
