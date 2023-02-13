#include "Sound.h"

Sound::Sound(): Common() {
    media_level = 0;
    call_level = 0;
    navi_level = 0;
    notification_level = 0;
}

Sound::~Sound() {

}

void Sound::nhapThongTin() {
	int media_level, call_level, navi_level, notification_level;
	string settingLevel = "(10|[0-9]){1}";
	
	cout << setw(16) << "Media level: ";
	media_level = checkInputInt(settingLevel);

	cout << setw(15) << "Call level: ";
	call_level = checkInputInt(settingLevel);

	cout << setw(21) << "Navigation level: ";
	navi_level = checkInputInt(settingLevel);

	cout << setw(23) << "Notification level: ";
	notification_level = checkInputInt(settingLevel);

	cout << setw(16) << "Media level: " << media_level << endl;
	cout << setw(15) << "Call level: " << call_level << endl;
	cout << setw(21) << "Navigation level: " << navi_level << endl;
	cout << setw(23) << "Notification level: " << notification_level << endl;
	
	set_media_level(media_level);
	set_call_level(call_level);
	set_navi_level(navi_level);
	set_notification_level(notification_level);
}

void Sound::xuatThongTin() {
	cout << setw(16) << "Media level: " << get_media_level() << endl;
	cout << setw(15) << "Call level: " << get_call_level() << endl;
	cout << setw(21) << "Navigation level: " << get_navi_level() << endl;
	cout << setw(23) << "Notification level: " << get_notification_level() << endl;
}

int Sound::get_media_level(){
    return media_level;
}

int Sound::get_call_level() {
    return call_level;
}

int Sound::get_navi_level() {
    return navi_level;
}

int Sound::get_notification_level() {
    return notification_level;
}

void Sound::set_media_level(int data) {
    media_level = data;
}

void Sound::set_call_level(int data) {
    call_level = data;
}

void Sound::set_navi_level(int data) {
    navi_level = data;
}
void Sound::set_notification_level(int data) {
    notification_level = data;
}


