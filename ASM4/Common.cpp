#include "Common.h"

Common::Common()
{
 	// Your code
}

Common::~Common(){
	
}
void Common::nhapThongTin() {
    // Your code
}

void Common::xuatThongTin() {
    // Your code
}

string Common::getCarName() {
    return car_name;
}

string Common::getPersonalKey() {
    return personal_key;
}

string Common::getEmail() {
    return email;
}

int Common::getODO (){
    return odo;
}

int Common::getServiceRemind(){
    return service_remind;
}

void Common::setCarName(string data) {
    car_name = data;
}

void Common::setEmail(string data) {
    email = data;
}

void Common::setPersonalKey(string data) {
    personal_key = data;
}

void Common::setODO(int data) {
    odo = data;
}

void Common::setServiceRemind(int data) {
    service_remind = data;
}

//check regex
bool Common::checkRegex(string input, string maRegex) {
	regex check(maRegex);
	if (!regex_match(input, check)) {
		return false;
	}
	else {
		return true;
	}
}

//check file rỗng
bool Common::checkEmptyFile(ifstream& checkFile) {
	if (checkFile.peek() == ifstream::traits_type::eof()) {
		return true;
	}
	else
		return false;
}

//check dữ liệu chuỗi nhập vào
string Common::checkInputString(string maRegex) {
	string inputData;
	bool accept = true;
	do {
		try {
			getline(cin, inputData);
			if (!checkRegex(inputData, maRegex)) {
				accept = false;
				throw "Khong hop le! Vui long nhap lai: ";
			}
			else {
				accept = true;
			}
		}
		catch (const char* msg) {
			cerr << msg;
		}
	} while (!accept);
	return inputData;
}

//check dữ liệu số nhập vào
int Common::checkInputInt(string maRegex) {
	string inputData;
	bool accept = true;
	do {
		try {
			getline(cin, inputData);
			if (!checkRegex(inputData, maRegex)) {
				accept = false;
				throw "Khong hop le! Vui long nhap lai: ";
			}
			else {
				accept = true;
			}
		}
		catch (const char* except) {
			cerr << except;
		}
	} while (!accept);
	return stoi(inputData);
}


