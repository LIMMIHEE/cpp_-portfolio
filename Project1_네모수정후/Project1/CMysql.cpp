#define HAVE_STRUCT_TIMESPEC
#include <iostream>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib,"libmySQL.lib")

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "Leeggo6476!"
#define DB_NAME "cppproject_mmp"
#define CHOP(x) x[strlen(x)-1] = ' '

#include "CMysql.h"
using namespace std;

CMysql::CMysql()
{

}


CMysql::~CMysql()
{
}

bool CMysql::Connect()
{
	mysql_init(&conn);

	//DB 연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	//DB연결에 문제 생기면 ERROR메세지 출력
	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connectino error : %s\n", mysql_error(&conn));
		return false;
	}

	return true;
}

bool CMysql::Close()
{
	mysql_close(connection);
	return true;
}

bool CMysql::ShowAllUser()
{
	//QUERY를 볼 수 있게 명령어를 넘김
	query_start = mysql_query(connection, "select * from user_info");
	//오류가 생기면 error메세지출력
	if (query_start != 0)
	{
		fprintf(stderr, "Mysql query error : %s\n", mysql_error(&conn));
		return false;
	}

	sql_result = mysql_store_result(connection);

	cout << "Num\t\tName\t\tID\t\tPASSWORD" << endl;

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
		cout << sql_row[0] << "\t" << sql_row[1] << "\t" << sql_row[2] << "\t" << sql_row[3] << endl;
	
	return true;
}

bool CMysql::InsertUser()
{
	cout << "\n -*-* Insert Value -*-*-\n";

	//입력받기
	cout << "NUM : ";
	fgets(num, 3, stdin);
	CHOP(id);

	cout << "ID : ";
	fgets(id, 10, stdin);
	CHOP(id);

	cout << "PassWord : ";
	fgets(password, 20, stdin);
	CHOP(password);

	cout << "Name : ";
	fgets(name, 80, stdin);
	CHOP(name);

	sprintf(query, "insert into user_info values ""('%s','%s', '%s', '%s')", num, id, password, name);
	query_start = mysql_query(connection, query);

	if (query_start != 0)
	{
		fprintf(stderr, "Mysql query error: %s\n", mysql_error(&conn));
		return false;
	}

	return true;
}

bool CMysql::Login()
{
	bool IDChk = false;
	bool PasswordChk = false;

	char buff2[255];

	int field1;
	int field2;

	string num1;
	string num2;

	//cout << "ID : ";
	//fgets(id, 10, stdin);
	//CHOP(id);  

	//cout << "PassWord : ";
	//fgets(password, 20, stdin);
	//CHOP(password);

	mysql_init(&conn);

	//DB 연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);

	//DB연결에 문제 생기면 ERROR메세지 출력
	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connectino error : %s\n", mysql_error(&conn));
		return false;
	}

	//QUERY를 볼 수 있게 명령어를 넘김
	query_start = mysql_query(connection, "select * from user_info");
	//오류가 생기면 error메세지출력
	if (query_start != 0)
	{
		fprintf(stderr, "Mysql query error : %s\n", mysql_error(&conn));
		return false;
	}

	sql_result = mysql_store_result(connection);




	cout << "insert ID : ";
	cin >> id;

	sprintf(buff2, "select * from user_info where ID = '%s'", id);
	mysql_query(connection, buff2);

	sql_result = mysql_store_result(connection);
	field1 = mysql_num_fields(sql_result);

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { //찾은 값이 있음	
		IDChk = true;
		num1 = sql_row[0];
	}


	cout << "insert Password : ";
	cin >> password;

	sprintf(buff2, "select * from user_info where password = '%s'", password);
	mysql_query(connection, buff2);

	sql_result = mysql_store_result(connection);
	field2 = mysql_num_fields(sql_result);

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { //찾은 값이 있음	
		PasswordChk = true;
		num2 = sql_row[0];
	}

	if (IDChk == true && PasswordChk == true && num1==num2) {
		system("cls");
		cout << "로그인 성공!_" << endl;
		return true;
	}
	else {
		system("cls");
		cout << "로그인 실패!_" << endl;
		return false;
	}

	return false;
}