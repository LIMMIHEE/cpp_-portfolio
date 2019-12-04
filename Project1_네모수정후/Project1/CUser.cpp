#include <iostream>
#include "CUser.h"
using namespace std;

CUser::CUser(int num, char* id,  char* password , char* name){ //User class
	Num = num;
	ID = new char[10];
	Password = new char[20];
	Name = new char[20];

	strcpy_s(ID, 20, id);
	strcpy_s(Password, 20, password);
	strcpy_s(Name, 20, name);
}

CUser::~CUser()
{
	delete ID, Password, Name;
}

void CUser::print() //user
{
	printf("|  %d   |   %s   |   %s   |   %s\n", Num, Name, ID, Password);
	cout << "+--------------------------------------------------------------------------+" << endl;
}

CUserManager::CUserManager()
{
	bstate = false;
	maxRow = 0;
}

void CUserManager::userPrint()
{
	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << "+  No  |   NUM   |  Name  |  ID  |  Password +" << endl;
	cout << "+--------------------------------------------------------------------------+" << endl;
	for (int i = 0; i < maxRow; i++)
	{
		user[i]->print();
	}
}

bool CUserManager::searchID(char* id)
{
	for (int i = 0; i < maxRow; i++)
	{
		if (strncmp(user[i]->getID(), id, strlen(id)) == 0)
		{
			cout << "+---------------------------------------+" << endl;
			cout << "+ NUM : " << user[i]->getNum() << endl;
			cout << "+ NAME : " << user[i]->getName() << endl;
			cout << "+ ID : " << user[i]->getID() << endl;
			cout << "+---------------------------------------+" << endl;
			return true;
		}
	}
	cout << "+ 검색실패 : 찾으시는 유저가 없습니다" << endl << endl;
	return false;
}

bool CUserManager::insertUser(int num, char* id, char* name, char* password)
{
	for (int i = 0; i < maxRow; i++)
	{
		if (strncmp(user[i]->getName(), name, strlen(name)) == 0 || user[i]->getNum() == num)
		{
			cout << "+ 중복되는 유저가 있어, 입력을 취소합니다." << endl << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
			cout << "+  No  |   NUM   |  Name  |  ID  |  Password +" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
			user[i]->print();
			return false;
		}
	}
	if (MAX_PATH > maxRow)
	{
		user[maxRow++] = new CUser(num , id, password, name);
		AllSaveToDB();
		cout << "+ 유저가 등록되었습니다" << endl << endl;
		return true;
	}
	else
	{
		cout << "+ 유저 등록 공간 부족" << endl << endl;
		return false;
	}
}
bool CUserManager::deleteUser(char* name , char* password)
{
	for (int i = 0; i < maxRow; i++)
	{
		if ((strncmp(user[i]->getName(), name, strlen(name)) == 0)&& (strncmp(user[i]->getPassword(), password, strlen(password)) == 0))
		{
			for (int j = i; j < maxRow - 1; j++)
				this->user[j] = this->user[j + 1];

			cout << "+ 유저가 삭제되었습니다" << endl << endl;
			maxRow--;
			return true;
		}
	}
	cout << "+ 삭제실패 : 찾으시는 유저가 없습니다" << endl << endl;
	return false;
}

bool CUserManager::AllSaveToDB()
{
	char str[256];
	if (mysql.Connect())
	{
		mysql.Query("delete from user_info");
		for (int i = 0; i < maxRow; i++)
		{
			printf(str, "insert into book value(%d,%s,%s,%s)", i + 1,
				user[i]->getNum(), user[i]->getID(), user[i]->getPassword(), user[i]->getName());
			mysql.Query(str);
		}
		DBDisconnect();
		return true;;
	}
	else
	{
		cout << "+ DB연결이 되지 않습니다." << endl << endl;
		return false;
	}
}
//////////////////////////////////////////////////////