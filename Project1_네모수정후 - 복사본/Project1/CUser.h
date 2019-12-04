#pragma once

#include "iostream"
#include "stdlib.h"
#include "CMysql.h"

#define MAX 10

class CUser
{
	int Num;
	char* ID;
	char* Name;
	char* Password;

public:
	CUser(int num, char* id, char* password, char* name);
	
	int getNum() { return Num; }
	char* getID() { return ID; }
	char* getName() { return Name; }
	char* getPassword() { return Password; }

	void print();

	~CUser();
};

class CUserManager
{
	CUser* user[MAX];
	CMysql mysql;
	bool bstate;
	int maxRow;
public:
	CUserManager();
	virtual ~CUserManager() {}

	void userPrint();
	bool searchID(char* id);
	bool insertUser(int num, char* id , char* name, char* password);
	bool deleteUser(char* name, char* password);

	bool AllSaveToDB();
	bool DBDisconnect();
	bool DBConnect();
};

