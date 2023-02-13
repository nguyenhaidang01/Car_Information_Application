#ifndef GENERAL_H_
#define GENERAL_H_
#define _CRT_SECURE_NO_WARNINGS

#include "Common.h"
#include <iostream>
#include <string>
using namespace std;

class General : public Common {

public:
	General();
	~General();
	void nhapThongTin();
	void xuatThongTin();

	string getLanguage();
	string getTimezone();

	void setLanguage(string data);
	void setTimezone(string data);

	void showTimeList();
	void showLangList(vector<string>& ltList);
	void downloadLTList(vector<string>& ltList, string fileName); //Sử dụng thư viện STL để SẮP XẾP
	
	void checkFileLT(string fileName); // kiểm soát ngoại lệ 2 file timezone, language
	
	void writeFileLanguage(); // Tạo hoặc viết lại file language
	void writeFileTime(); // Tạo hoặc viết lại file timezone

private:
	string language;
	string timezone;
};

#endif /* GENERAL_H_ */

