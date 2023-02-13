#include "Setting.h"

Setting::Setting() {
	display = new Display();
	sound = new Sound();
	general = new General();
}
Setting::~Setting() {

}

void Setting::setTotalNumCar(int data) {
	totalNumCar = data;
}
int Setting::getTotalNumCar() {
	return totalNumCar;
}

//Nhập Common Infor
void Setting::nhapThongTin() {
	string ownerName, email, key;
	int odo, service;

	string checkName = "[a-zA-Z]+\\s[a-zA-Z]+(\\s[a-zA-Z]+)*";
	string checkEmail = "[A-Za-z0-9_]{2,}\.@[A-Za-z]{2,}\.([A-Za-z]{3})";

	string checkKey = "[0-9]{8}";
	string checkODOService = "[0-9]+";

	cout << "Car index: " << totalNumCar + 1 << endl;
	cout << setw(15) << "Owner name: ";
	ownerName = checkInputString(checkName);
	for (int i = 0; i < ownerName.length(); i++) {
		if (ownerName[i] >= 97 && ownerName[i] <= 122)
			ownerName[i] = ownerName[i] - 32;
	}
	system("cls");
	
	cout << "Car index: " << totalNumCar + 1 << endl;
	cout << setw(15) << "Owner name: " << ownerName << endl;
	cout << setw(10) << "Email: ";
	email = checkInputString(checkEmail);
	system("cls");
	
	cout << "Car index: " << totalNumCar + 1 << endl;
	cout << setw(15) << "Owner name: " << ownerName << endl;
	cout << setw(10) << "Email: " << email << endl;
	cout << setw(15) << "Key number: ";
	key = checkInputString(checkKey);
	system("cls");

	cout << "Car index: " << totalNumCar + 1 << endl;
	cout << setw(15) << "Owner name: " << ownerName << endl;
	cout << setw(10) << "Email: " << email << endl;
	cout << setw(15) << "Key number: " << key << endl;
	cout << setw(15) << "ODO number: ";
	odo = checkInputInt(checkODOService);
	system("cls");

	cout << "Car index: " << totalNumCar + 1 << endl;
	cout << setw(15) << "Owner name: " << ownerName << endl;
	cout << setw(10) << "Email: " << email << endl;
	cout << setw(15) << "Key number: " << key << endl;
	cout << setw(15) << "ODO number: " << odo << endl;
	cout << setw(19) << "Remind service: ";
	service = checkInputInt(checkODOService);
	system("cls");
	cout << "Car index: " << totalNumCar + 1 << endl;
	cout << setw(15) << "Owner name: " << ownerName << endl;
	cout << setw(10) << "Email: " << email << endl;
	cout << setw(15) << "Key number: " << key << endl;
	cout << setw(15) << "ODO number: " << odo << endl;
	cout << setw(19) << "Remind service: " << service << endl;
	
	setCarName(ownerName);
	setEmail(email);
	setPersonalKey(key);
	setODO(odo);
	setServiceRemind(service);
}

void Setting::xuatThongTin() {
	cout << setw(15) << "Owner name: " << getCarName() << endl;
	cout << setw(10) << "Email: " << getEmail() << endl;
	cout << setw(15) << "Key number: " << getPersonalKey() << endl;
	cout << setw(15) << "ODO number: " << getODO() << endl;
	cout << setw(19) << "Remind service: " << getServiceRemind() << endl;
}

void Setting::setDisplay(Display* data) {
	display = data;
}

Display* Setting::getDisplay() {
	return display;
}

void Setting::setSound(Sound* data) {
	sound = data;
}

Sound* Setting::getSound() {
	return sound;
}

void Setting::setGeneral(General* data) {
	general = data;
}

General* Setting::getGeneral() {
	return general;
}


