#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <iomanip>
#include <string>
#include<regex>
#include<fstream>
#include<vector>

using namespace std;

class Common {
public:
	Common();
	virtual ~Common();
	virtual void nhapThongTin();
	virtual void xuatThongTin();
	
	string getCarName();
	string getPersonalKey();
	string getEmail();
	int getODO ();
	int getServiceRemind();

	void setCarName(string data);
	void setPersonalKey(string data);
	void setEmail(string data);
	void setODO(int data);
	void setServiceRemind(int data);

	bool checkRegex(string data, string f); //check regex
	bool checkEmptyFile(ifstream& checkFile); //check file rỗng
	int checkInputInt(string maRegex); //check dữ liệu số nhập vào
	string checkInputString(string maRegex); //check dữ liệu chuỗi nhập vào

private:
	string car_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
};
#endif /* COMMON_H_ */

