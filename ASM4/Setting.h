#pragma once
#ifndef SETTING_H_
#define SETTING_H_
#include "Common.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"

class Setting : public Common {
public:
	Setting();
	~Setting();

	void nhapThongTin(); //Nhập Common Infor
	void xuatThongTin(); 

	void setDisplay(Display* data);
	Display* getDisplay();

	void setSound(Sound* data);
	Sound* getSound();

	void setGeneral(General* data);
	General* getGeneral();

	void setTotalNumCar(int data);
	int getTotalNumCar();

private:
	Display* display;
	Sound* sound;
	General* general;
	int totalNumCar; //tổng số xe

};
#endif /* SETTING_H_ */

