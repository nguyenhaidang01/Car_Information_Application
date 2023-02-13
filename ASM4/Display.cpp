#include "Display.h"

Display::Display(): Common()
{
    light_level = 0;
    screen_light_level = 0;
    taplo_light_level = 0;
}

Display::~Display(){

}

void Display::nhapThongTin() {
	int light_level, screen_light_level, taplo_light_level;
	string settingLevel = "(10|[0-9]){1}";

	cout << setw(16) << "Light level: ";
	light_level = checkInputInt(settingLevel);

	cout << setw(23) << "Screen light level: ";
	screen_light_level = checkInputInt(settingLevel);

	cout << setw(22) << "Taplo light level: ";
	taplo_light_level = checkInputInt(settingLevel);
	
	set_light_level(light_level);
	set_screen_light_level(screen_light_level);
	set_taplo_light_level(taplo_light_level);
}

void Display::xuatThongTin() {
	cout << setw(16) << "Light level: " << get_light_level() << endl;
	cout << setw(23) << "Screen light level: " << get_screen_light_level() << endl;
	cout << setw(22) << "Taplo light level: " << get_taplo_light_level() << endl;
}

int Display::get_light_level() {
    return light_level;
}

int Display::get_screen_light_level() {
    return screen_light_level;
}

int Display::get_taplo_light_level() {
    return taplo_light_level;
}

void Display::set_light_level(int data) {
    light_level = data;
}

void Display::set_screen_light_level(int data) {
    screen_light_level = data;
}

void Display::set_taplo_light_level(int data) {
    taplo_light_level = data;
}



