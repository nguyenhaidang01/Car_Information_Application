#ifndef SOUND_H_
#define SOUND_H_

#include "Common.h"
#include <iostream>
#include <string>
using namespace std;

class Sound : public Common {

public:
	Sound();
	~Sound();
	void nhapThongTin();
	void xuatThongTin();

	int get_media_level();
	int get_call_level();
	int get_navi_level();
	int get_notification_level();

	void set_media_level(int data);
	void set_call_level(int data);
	void set_navi_level(int data);
	void set_notification_level(int data);

private:
	int media_level;
	int call_level;
	int navi_level;
	int notification_level;
};

#endif /* DISPLAY_H_ */

