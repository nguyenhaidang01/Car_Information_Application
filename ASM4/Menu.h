#pragma once
#ifndef MENU_H_
#define MENU_H_
#define _CRT_SECURE_NO_WARNINGS
#include "Common.h"
#include "Setting.h"
#include "binaryTree.h"

class Menu:public Common {
public:
	void NhapXuatThongTin();
	void NhapThongTinCaiDat();
	void XuatThongTinCaiDat();
	
	void NhapThongTinCaiDat_Chung(string type);
	void XuatThongTinCaiDat_Chung(string type);
	
	void readSettingInfo(); //kiểm soát ngoại lệ và đọc file Setting.txt
	void writeSettingInfo();  //kiểm soát ngoại lệ và lưu dữ liệu vào file Setting.txt
			
	void InputCommonInfo(Setting* tempCar); //Nhập Common Infor
	void showCommonInfo(Setting* tempCar); //In Common Infor

private:
	int selection1;
	int selection2;
	char selection3;
	
	bool overwrite; //xe vừa nhập vào có trùng không?

	node* keyTree;
	node* nameTree;
	binaryTree tree;
};
#endif //MENU_H_
