#include <iostream>

#include <fstream>

#include <iostream>

#include <sstream>

#include "CProjectManager.h"

using namespace std;

bool CProjectManager::InsertProject(int num, string event_name, string event_chk, string event_star, string event_info, string ecnet_info_def)
{
	system("cls");
	cout << "Project Insert" << endl;

	ofstream fout(filepath, ios::app);

	if (!fout.is_open()) {

		cout << "파일 열기 오류" << endl;

		return false;

	}

	fout << "No." << num << endl << "프로젝트 이름 : " << event_name << endl << "프로젝트 종류 : " << event_chk << endl << "프로젝트 중료도 : " << event_star << endl
		<< "프로젝트 작은 감상 ; " << event_info << endl << "프로젝트 큰 감상 : " << ecnet_info_def << endl << "No." << num  << "끝" << endl;

	fout.close();

	return true;

	return true;
}

CProjectManager::CProjectManager()
{
	this->filepath = "D:\\Leeyeseul\\git_Example\\cpp_-portfolio-master\\cpp_-portfolio-master\\Project1_네모수정후\\Project1\\Project.txt";
}

CProjectManager::CProjectManager(string filepath) {

	this->filepath = filepath;

}



CProjectManager::~CProjectManager()
{

}

