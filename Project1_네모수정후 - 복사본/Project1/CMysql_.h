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

	my_ulonglong iRowNum;				//레코드셋의 개수
	unsigned int iFieldNum;				 //필드의 개수
	my_ulonglong iCurrentPos;			//현재 row 의 offset

	bool bHaveResultQuery;				//결과가 있는 쿼리인가요?
	bool bIsEof;						//레코드셋의 처음인가요?
	bool bIsBof;						//레코드셋의 마지막인가요?
	bool bIsConnect;					//연결이 되어 있는가?

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
