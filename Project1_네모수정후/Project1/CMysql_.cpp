#define HAVE_STRUCT_TIMESPEC

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "Leeggo6476!"
#define DB_NAME "cppproject_mmp"
#define CHOP(x) x[strlen(x)-1] = ' '

#include <iostream>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib,"libmySQL.lib")

#include "CMysql.h"

//Constructor and Destructor
CMysql::CMysql()
{
	iRowNum = 0;
	iFieldNum = 0;
	iCurrentPos = 0;

	bIsBof = false;
	bIsEof = false;
	bIsConnect = false;
	bHaveResultQuery = false;

}

CMysql::~CMysql()
{
	if (&conn != NULL)
	{
		mysql_close(&conn);
	}
}

bool CMysql::Connect()
{
	MYSQL* connection = NULL, conn;

	mysql_init(&conn);

	//DB���ῡ ���� ����� ERROR�޼��� ���
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connectino error : %s\n", mysql_error(&conn));
		return 1;
	}

	if (&conn == NULL)
	{
		cout << "[Error:" << mysql_errno(&conn) << "] " << mysql_error(&conn) << endl;
		exit(1);
	}

	if (mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0) == NULL)
	{
		IsConnect(false);
		fprintf(stderr, "Mysql connectino error : %s\n", mysql_error(&conn));
		return false;
	}

	IsConnect(true);
	return true;
}

void CMysql::Disconnect() 
{
	if (&conn != NULL)
	{
		mysql_close(&conn); 
		iRowNum = 0;
		iFieldNum = 0;
		iCurrentPos = 0;
		bIsBof = false;
		bIsEof = false;
		bIsConnect = false;
		bHaveResultQuery = false;
	}
}

bool CMysql::SelectDB(const char* szString)
{
	return !mysql_select_db(&conn, szString);
}

bool CMysql::Query(const char* szString)
{
	if (&conn == NULL || !IsConnect())
	{
		cout << "[Error:" << mysql_errno(&conn) << "] " << mysql_error(&conn) << endl;
		exit(1);
	}

	if (mysql_query(&conn, szString)) //raise error
	{
		return false;
	}
	else
	{
		pres = mysql_store_result(&conn); //����� �����ϰ�
		if (pres)
		{
			//OK,������ ������ ���� ����
			iRowNum = mysql_num_rows(pres);
			iFieldNum = mysql_num_fields(pres);
			row = mysql_fetch_row(pres);
			pfield = mysql_fetch_fields(pres); //pfield[iFieldNum].name;
			IsBOF(true);
			IsEOF(false);
			bHaveResultQuery = true;
			return true;
		}
		else
		{
			//Update, Delete, insert query
			if (mysql_field_count(&conn) == 0)
			{
				iRowNum = mysql_affected_rows(&conn);
				bHaveResultQuery = false;
				return true;
			}
			else
			{
				//raise error
				return false;
			}
		}
	}
	return true;
}

char* CMysql::Field(const char* szFieldName)
{
	//����� �ִ� �������� ����
	if (!bHaveResultQuery)
	{
		cout << "Exception Field() or [], ����� ���� ������ �����߽��ϴ�" << endl;
		cout << "[Error:" << mysql_errno(&conn) << "] " << mysql_error(&conn) << endl;
		exit(1);
	}
	if (iRowNum == 0)
	{
		cout << "Exception Field() or [], Query �� �ش��ϴ� ���ڵ���� �����ϴ�" << endl;
		cout << "[Error:" << mysql_errno(&conn) << "] " << mysql_error(&conn) << endl;
		exit(1);
	}
	//�ʵ��̸��� �ִ��� ���� �ִٸ� �ε����� ��������!
	for (unsigned int i = 0; i < iFieldNum; i++)
	{
		if (strcmp(pfield[i].name, szFieldName) == 0)
		{
			return row[(int)i];
		}
	}
	return row[-1];
}
char* CMysql::Field(const my_ulonglong iFieldIndex)
{
	//����� �ִ� �������� ����
	if (!bHaveResultQuery)
	{
		cout << "Exception Field() or [], ����� ���� ������ �����߽��ϴ�" << endl;
		cout << "[Error:" << mysql_errno(&conn) << "] " << mysql_error(&conn) << endl;
		exit(1);
	}
	if (iRowNum == 0)
	{
		cout << "Exception Field() or [], Query �� �ش��ϴ� ���ڵ���� �����ϴ�" << endl;
		cout << "[Error:" << mysql_errno(&conn) << "] " << mysql_error(&conn) << endl;
		exit(1);
	}
	if (iFieldIndex > iFieldNum)
	{
		cout << "Exception field() or [], �ʵ��� �ε����� �����̰ų� ������ �ѽ��ϴ�" << endl;
		cout << "[Error:" << mysql_errno(&conn) << "] " << mysql_error(&conn) << endl;
		exit(1);
	}
	return row[iFieldIndex];
}

void CMysql::First()
{
	IsBOF(true);
	IsEOF(false);
	iCurrentPos = 0;
	mysql_data_seek(pres, iCurrentPos);
	row = mysql_fetch_row(pres);
}

void CMysql::Last()
{
	IsBOF(false);
	IsEOF(true);
	iCurrentPos = iRowNum - 1;  //row ��index �� 0 ���ʹ�
	mysql_data_seek(pres, iCurrentPos);
	row = mysql_fetch_row(pres);
}

void CMysql::Next()
{
	if (!IsEOF())
	{
		Move(1);
		if (IsBOF())
		{
			IsBOF(false); //Next() �� �ϸ� ó���� �ƴϴ�
		}
	}
	else
	{
		cout << "[EXCEPTION] Exception Next(), ���� ���ڵ���� �����ϴ�. ";
		exit(1);
	}
}

void CMysql::Prev()
{
	if (!IsBOF())
	{
		Move(-1);
		if (IsEOF())
		{
			IsEOF(false); //Prev() �� �ϸ� ���� �ƴϴ�
		}
	}
	else
	{
		cout << "Exception Prev(), ���� ���ڵ���� �����ϴ�." << endl;
		cout << "[Error:" << mysql_errno(&conn) << "] " << mysql_error(&conn) << endl;
		exit(1);
	}
}

void CMysql::Move(int n)
{
	//������ �Ѵ��� ����.
	my_ulonglong pos = iCurrentPos + n;
	if (pos == -1)
	{
		IsBOF(true);
		IsEOF(false);
	}
	else if (pos == iRowNum)
	{
		IsBOF(false);
		IsEOF(true);
	}
	else if ((pos < 0) || (pos > iRowNum))
	{
		cout << "Exception Prev() or Next() or Move(), ���ڵ�¹����� �ѽ��ϴ�" << endl;
		cout << "[Error:" << mysql_errno(&conn) << "] " << mysql_error(&conn) << endl;
		exit(1);
	}
	iCurrentPos = pos;
	mysql_data_seek(pres, iCurrentPos);
	row = mysql_fetch_row(pres);
}
