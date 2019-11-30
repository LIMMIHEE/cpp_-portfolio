#define HAVE_STRUCT_TIMESPEC
#include <my_global.h>
#include <mysql.h>
#include <tchar.h>

#include <string>
#include <iostream>

#pragma comment(lib,"libmySQL.lib")
using namespace std;

int main() {
	MYSQL mysql;
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "Leeggo6476!", "db1029", 3306, NULL, 0))
		cout << "error" << endl;
	else
		cout << "success" << endl;
	mysql_close(&mysql);

	return 0;
}