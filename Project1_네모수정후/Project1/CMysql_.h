#pragma once

#define HAVE_STRUCT_TIMESPEC
#include <iostream>
#include <my_global.h>
#include <mysql.h>

#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib,"libmySQL.lib")
#pragma warning(disable:4996)



#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "Leeggo6476!"
#define DB_NAME "cppproject_mmp"
#define CHOP(x) x[strlen(x)-1] = ' '
using namespace std;

class CMysql
{
	MYSQL conn;
	MYSQL_RES* pres;
	MYSQL_ROW row;
	MYSQL_FIELD* pfield;

	my_ulonglong iRowNum;				//���ڵ���� ����
	unsigned int iFieldNum;				 //�ʵ��� ����
	my_ulonglong iCurrentPos;			//���� row �� offset

	bool bHaveResultQuery;				//����� �ִ� �����ΰ���?
	bool bIsEof;						//���ڵ���� ó���ΰ���?
	bool bIsBof;						//���ڵ���� �������ΰ���?
	bool bIsConnect;					//������ �Ǿ� �ִ°�?

public:
	CMysql();
	virtual ~CMysql();

	bool Connect();
	void Disconnect();

	bool IsConnect() { return bIsConnect; }
	void IsConnect(bool b) { bIsConnect = b; }
	bool Query(const char* szString);
	bool SelectDB(const char* szString);

	//result navigation
	bool IsBOF() { return bIsBof; }
	void IsBOF(bool b) { bIsBof = b; }
	bool IsEOF() { return bIsEof; }
	void IsEOF(bool b) { bIsEof = b; }
	void First();
	void Last();
	void Next();
	void Prev();
	void Move(int n = 1);

	char* Field(const char* szFieldName);
	char* Field(const my_ulonglong iFieldIndex);

	//operator
	char* operator[](const my_ulonglong iFieldIndex) { return Field(iFieldIndex); }
	char* operator[](const char* szFieldName) { return Field(szFieldName); }
};
