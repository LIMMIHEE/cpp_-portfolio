#include<string>
#include<iostream>
#include <fstream>
using namespace std;



int main() {


	ifstream input("input.txt");

	if (input.fail()) {
		cout << "������ ���� �� �����߽��ϴ�." << endl;
		return 1;
	}



	string line;
	int start_num, end_num, p_line = 0;
	
	while (!input.eof()) {
		if(p_line < 5){
			getline(input, line);
			end_num = line.length();

			if (line.find(':') >= 0) {
				start_num= line.find(':') ;
				string ch_text= line.substr(start_num+1, end_num);
				cout << ch_text<<endl;
			}
		}
		else {
			break;
		}
		p_line++;
	}

	input.close();



	return 0;

}

