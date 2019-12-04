#include <mysql.h>
#pragma once
class CMysql
{
public:
	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;
	int query_start;

	char num[4];
	char id[10];
	char password[20];
	char name[80];
	char query[255];

	CMysql();
	virtual ~CMysql();
	bool Connect();
	bool Close();
	bool ShowAllUser();
	bool InsertUser();
	bool Login();

};

