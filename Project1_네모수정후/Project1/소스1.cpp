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

using namespace std;

int main() {
	
	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;
	int query_start;

	char num[4];
	char id[10];
	char password[20];
	char name[80];
	char query[255];

	mysql_init(&conn);

	//한글사용을위해추가.

	//mysql_query(connection, "set session character_set_connection=euckr;");
	//mysql_query(connection, "set session character_set_results=euckr;");
	//mysql_query(connection, "set session character_set_client=euckr;");

	//DB 연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	//DB연결에 문제 생기면 ERROR메세지 출력
	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connectino error : %s\n", mysql_error(&conn));
		return 1;
	}

	//QUERY를 볼 수 있게 명령어를 넘김
	query_start = mysql_query(connection, "select * from user_info");
	//오류가 생기면 error메세지출력
	if (query_start != 0)
	{
		fprintf(stderr, "Mysql query error : %s\n", mysql_error(&conn));
		return 1;
	}

	sql_result = mysql_store_result(connection);
	cout << "Num\t\tName\t\tID\t\tPASSWORD" << endl;

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
		cout << sql_row[0] << "\t" << sql_row[1] << "\t" << sql_row[2] << "\t" << sql_row[3] << endl;
	
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

	sprintf(query, "insert into user_info values ""('%s','%s', '%s', '%s')",num, id, password, name);
	query_start = mysql_query(connection, query);

	if (query_start != 0)
	{
		fprintf(stderr, "Mysql query error: %s\n", mysql_error(&conn));
		return 1;
	}

	mysql_close(connection);

	return 0;
}

