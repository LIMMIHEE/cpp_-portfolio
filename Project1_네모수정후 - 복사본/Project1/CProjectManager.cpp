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

		cout << "���� ���� ����" << endl;

		return false;

	}

	fout << "No." << num << endl << "������Ʈ �̸� : " << event_name << endl << "������Ʈ ���� : " << event_chk << endl << "������Ʈ �߷ᵵ : " << event_star << endl
		<< "������Ʈ ���� ���� ; " << event_info << endl << "������Ʈ ū ���� : " << ecnet_info_def << endl << "No." << num  << "��" << endl;

	fout.close();

	return true;

	return true;
}

CProjectManager::CProjectManager()
{
	this->filepath = "D:\\Leeyeseul\\git_Example\\cpp_-portfolio-master\\cpp_-portfolio-master\\Project1_�׸������\\Project1\\Project.txt";
}

CProjectManager::CProjectManager(string filepath) {

	this->filepath = filepath;

}



CProjectManager::~CProjectManager()
{

}

