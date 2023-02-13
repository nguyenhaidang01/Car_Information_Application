#include"Menu.h"
#include"binaryTree.h"

//In Common Infor
void Menu::showCommonInfo(Setting* tempCar) {
	int i;
	if (overwrite) {
		i = tree.countNumNode(keyTree);
	} else {
		i = tree.countNumNode(keyTree) + 1;
	}	
	cout << "Car index: " << i << endl;
	cout << setw(15) << "Owner name: " << tempCar->getCarName() << endl;
	cout << setw(10) << "Email: " << tempCar->getEmail() << endl;
	cout << setw(15) << "Key number: " << tempCar->getPersonalKey() << endl;
	cout << setw(15) << "ODO number: " << tempCar->getODO() << endl;
	cout << setw(19) << "Remind service: " << tempCar->getServiceRemind() << endl;
	if (!overwrite) {
		cout << "->This is car data will be appended to your list" << endl;
	}
	else {
		cout << "->This car already existed, data will be overridden" << endl;
	}
}

//kiểm soát ngoại lệ và đọc file Setting.txt
void Menu::readSettingInfo() {

	ifstream inputFile("Setting.txt");
	try
	{
		if (inputFile.fail()) {
			throw "File Setting.txt is not Exist!";
		}
		else if (checkEmptyFile(inputFile)) {
			throw 208;
		}
		else if (inputFile.is_open()) {
		
			while (!inputFile.eof()) {			
				Setting* tempCar = new Setting();
				string tempSave;
				string name, email, keyNumber, odoNumber, remindService;
				string lightLevel, screenLight, taploLight;
				string media, call, navigation, notification;
				string language, timezone;

				//get Common Info
				getline(inputFile, tempSave, ' ');
				getline(inputFile, name, ',');
				getline(inputFile, email, ',');
				getline(inputFile, keyNumber, ',');
				getline(inputFile, odoNumber, ',');
				getline(inputFile, remindService, ' ');

				//get Display Info
				getline(inputFile, tempSave, ' ');
				getline(inputFile, lightLevel, ',');
				getline(inputFile, screenLight, ',');
				getline(inputFile, taploLight, ';');

				//get Sound Info
				getline(inputFile, tempSave, ' ');
				getline(inputFile, call, ',');
				getline(inputFile, media, ',');
				getline(inputFile, navigation, ',');
				getline(inputFile, notification, ';');

				//get General Info
				getline(inputFile, tempSave, ' ');
				getline(inputFile, timezone, ',');
				getline(inputFile, language, ';');

				
				tempCar->setCarName(name);
				tempCar->setEmail(email);
				tempCar->setPersonalKey(keyNumber);
				tempCar->setODO(stoi(odoNumber));
				tempCar->setServiceRemind(stoi(remindService));

				tempCar->getDisplay()->set_light_level(stoi(lightLevel));
				tempCar->getDisplay()->set_screen_light_level(stoi(screenLight));
				tempCar->getDisplay()->set_taplo_light_level(stoi(taploLight));

				tempCar->getSound()->set_call_level(stoi(call));
				tempCar->getSound()->set_media_level(stoi(media));
				tempCar->getSound()->set_navi_level(stoi(navigation));
				tempCar->getSound()->set_notification_level(stoi(notification));

				tempCar->getGeneral()->setTimezone(timezone);
				tempCar->getGeneral()->setLanguage(language);
					
				keyTree = tree.insertKeyTree(keyTree, tempCar);
				nameTree = tree.insertNameTree(nameTree, tempCar);
			}	
			inputFile.close();
		}
	}
	catch (int) {

	}
	catch (const char* msg) {
		cout << msg << endl;
	}
	catch (...) {

	}
}

//kiểm soát ngoại lệ và lưu dữ liệu vào file Setting.txt
void Menu::writeSettingInfo() {	
	ofstream fileOut("Setting.txt", ios::trunc);
	try {
		if (fileOut.is_open()) {
			fileOut << "";
			fileOut.close();
		}
		else {
			throw exception();
		}
	}
	catch (...) {
		cout << "Loi ghi file!" << endl;
	}
	fileOut.close();
	tree.writeNodeInfo(keyTree);
}

//Nhập Common Infor
void Menu::InputCommonInfo(Setting* tempCar) {
	tempCar->setTotalNumCar(tree.countNumNode(keyTree));
	tempCar->nhapThongTin();
	if (tree.checkExist(keyTree, tempCar)==0) {
		overwrite = false;
	}
	else {
		overwrite = true;
		cout << "->This car already existed, data will be overridden" << endl;
	}

	if (!overwrite) {
		cout << "->This is car, data will be appended to your list" << endl;
	}
}

void Menu::NhapThongTinCaiDat_Chung(string type) {
	string nextCar = "[yn]{1}";
	Setting* tempCar = new Setting();

	InputCommonInfo(tempCar);
	// Kiểm tra và nhập vào 3 thông tin của setting display
	if (type == "Display") {
		tempCar->getDisplay()->nhapThongTin();
	}
	if (type == "Sound") {
		tempCar->getSound()->nhapThongTin();
	}
	if (type == "General") {
		tempCar->getGeneral()->nhapThongTin();
	}

	if (overwrite) {
		tree.replaceData(keyTree, tempCar, type);
		tree.replaceData(nameTree, tempCar, type);
	}
	else {
		keyTree = tree.insertKeyTree(keyTree, tempCar);
		nameTree = tree.insertNameTree(nameTree, tempCar);
	}
	writeSettingInfo();
	system("cls");

	cout << "Car index: " << tree.countNumNode(keyTree) << endl;
	tempCar->xuatThongTin();
	if (overwrite) {
		cout << "->This car already existed, data will be overridden" << endl;
	}
	else {
		cout << "->This is car, data will be appended to your list" << endl;
	}

	if (type == "Display") {
		tempCar->getDisplay()->xuatThongTin();
	}
	if (type == "Sound") {
		tempCar->getSound()->xuatThongTin();
	}
	if (type == "General") {
		tempCar->getGeneral()->xuatThongTin();
	}

	cout << "Will you input for car " << tree.countNumNode(keyTree) + 1 << " (y/n)?: ";
	string str = checkInputString(nextCar);
	system("cls");

	if (str == "y") {
		selection3 = 'y';
	}
	else {
		selection3 = 'n';
	}
	switch (selection3) {
	case 'y': {
		NhapThongTinCaiDat_Chung(type);
		break;
	}
	case 'n': {
		break;
	}
	}
}

void Menu::XuatThongTinCaiDat_Chung(string type) {
	node* tempNode = new node();
	ifstream checkFile("Setting.txt");
	switch (checkEmptyFile(checkFile)) {
	case true: {
		cout << "---" << type << " setting--- " << endl;
		cout << "Setting Information is Empty!" << endl;
		system("pause");
		system("cls");
		break;
	}
	case false: {
		switch (tree.countNumNode(keyTree)) {
		case 1: {
			if (type == "Display") {
				cout << "---Display setting---" << endl;
				cout << left << setw(25) << "Owner Name" << left << setw(20) << "Email" << left << setw(12) << "Key" << left << setw(10)
					<< "ODO" << left << setw(10) << "SEVICES" << left << setw(10) << "Light" << left << setw(10) << "Screen" << left << setw(10) << "Taplo" << endl;
				tree.showNodeInfor(keyTree, "Display");

			}
			if (type == "Sound") {
				cout << "---Sound setting---" << endl;
				cout << left << setw(25) << "Owner Name" << left << setw(20) << "Email" << left << setw(12) << "Key" << left << setw(10) << "ODO"
					<< left << setw(10) << "SEVICES" << left << setw(10) << "Media" << left << setw(10) << "Call" << left << setw(10) << "Navi" << left << setw(10) << "Notify" << endl;
				tree.showNodeInfor(keyTree, "Sound");
			}
			if (type == "General") {
				cout << "---General setting---" << endl;
				cout << left << setw(25) << "Owner Name" << left << setw(20) << "Email" << left << setw(12) << "Key"
					<< left << setw(10) << "ODO" << left << setw(10) << "SEVICES" << left << setw(12) << "TimeZone" << left << setw(15) << "Language" << endl;
				tree.showNodeInfor(keyTree, "General");
			}
			if (type == "All") {
				tree.showNodeInfor(keyTree, "All");
				tree.coutSerial(true);
			}
			system("pause");
			system("cls");
			break;
		}
		default: {
			int str;
			string sortBy= "[12]{1}";
			if (type == "All") {
				sortBy = "[1-4]{1}";
			}
			cout << "---" << type << " setting--- " << endl;
			cout << "1. Show " << type << " setting sort by Name" << endl;
			cout << "2. Show " << type << " setting sort by Key" << endl;
			if (type == "All") {
				cout << "3. Search setting by Name" << endl;
				cout << "4. Search setting by Key" << endl;
			}
			cout << "Your selection: ";
			str = checkInputInt(sortBy);
			system("cls");
			
			cout << "---" << type << " setting--- " << endl;
			if (type == "Display") {
				cout << left << setw(25) << "Owner Name" << left << setw(20) << "Email" << left << setw(12) << "Key" << left << setw(10)
					<< "ODO" << left << setw(10) << "SEVICES" << left << setw(10) << "Light" << left << setw(10) << "Screen" << left << setw(10) << "Taplo" << endl;
				if (str == 1) {
					tree.showNodeInfor(nameTree, "Display");
				}
				else {
					tree.showNodeInfor(keyTree, "Display");
				}			
			}
			if (type == "Sound") {
				cout << left << setw(25) << "Owner Name" << left << setw(20) << "Email" << left << setw(12) << "Key" << left << setw(10) << "ODO"
					<< left << setw(10) << "SEVICES" << left << setw(10) << "Media" << left << setw(10) << "Call" << left << setw(10) << "Navi" << left << setw(10) << "Notify" << endl;
				if (str == 1) {
					tree.showNodeInfor(nameTree, "Sound");
				}
				else {
					tree.showNodeInfor(keyTree, "Sound");
				}
			}
			if (type == "General") {
				cout << left << setw(25) << "Owner Name" << left << setw(20) << "Email" << left << setw(12) << "Key"
					<< left << setw(10) << "ODO" << left << setw(10) << "SEVICES" << left << setw(15) << "TimeZone" << left << setw(15) << "Language" << endl;
				if (str == 1) {
					tree.showNodeInfor(nameTree, "General");
				}
				else {
					tree.showNodeInfor(keyTree, "General");
				}
			}
			if (type == "All") {
				bool* infoExist = new bool;
				*infoExist = false;
				if (str == 1) {
					tree.showNodeInfor(nameTree, "All");
					tree.coutSerial(true);
				}
				if (str == 2) {
					tree.showNodeInfor(keyTree, "All");
					tree.coutSerial(true);
				}
				if (str == 3) {
					string checkName = "[a-zA-Z]+\\s[a-zA-Z]+(\\s[a-zA-Z]+)*";					
					cout << setw(15) << "Enter Name: ";
					string ownerName = checkInputString(checkName);
					for (int i = 0; i < ownerName.length(); i++) {
						if (ownerName[i] >= 97 && ownerName[i] <= 122)
							ownerName[i] = ownerName[i] - 32;
					}
					system("cls");
					cout << "---" << type << " setting--- " << endl;
					cout << setw(15) << "Enter Name: " << ownerName << endl;
					tree.searchNode(keyTree, "Name", ownerName, infoExist);
					tree.coutSerial(true);
					if (!*infoExist) {
						cout << "No Information Found!" << endl;
					}
					*infoExist = false;
				}
				if (str == 4) {
					string checkKey = "[0-9]{8}";
					cout << setw(15) << "Enter Key: ";
					string personKey = checkInputString(checkKey);
					tree.searchNode(keyTree, "Key", personKey, infoExist);
					tree.coutSerial(true);
					if (!*infoExist) {
						cout << "No Information Found!" << endl;
					}
					*infoExist = false;
				}
			}		
			system("pause");
			system("cls");
		}
		}
	}
	}
}

void Menu::NhapThongTinCaiDat() {
	do {
		string reMa = "[0-3]{1}";
		cout << "---SELECT MENU---" << endl;
		cout << "1. Display setting" << endl;
		cout << "2. Sound setting" << endl;
		cout << "3. General setting" << endl;
		cout << "0. Exit" << endl;
		cout << "Your selection: ";
		selection2 = checkInputInt(reMa);				
		system("cls");
		switch (selection2) {
		case 1: {
			NhapThongTinCaiDat_Chung("Display");
			break;
		}
		case 2: {
			NhapThongTinCaiDat_Chung("Sound");
			break;
		}
		case 3: {
			NhapThongTinCaiDat_Chung("General");
			break;
		}
		case 0: {
			break;
		}
		}
	} while (selection2 != 0);
}

void Menu::XuatThongTinCaiDat() {
	do {
		string reMa = "[1-5]{1}";
		cout << "---SELECT MENU---" << endl;
		cout << "1. Print Display setting information" << endl;
		cout << "2. Print Sound setting information" << endl;
		cout << "3. Print General setting information" << endl;
		cout << "4. Print all setting information" << endl;
		cout << "5. Exit" << endl;
		cout << "Your selection: ";
		selection2 = checkInputInt(reMa);
		system("cls");
		switch (selection2) {
		case 1: {
			XuatThongTinCaiDat_Chung("Display");
			break;
		}
		case 2: {
			XuatThongTinCaiDat_Chung("Sound");
			break;
		}
		case 3: {
			XuatThongTinCaiDat_Chung("General");
			break;
		}
		case 4: {
			XuatThongTinCaiDat_Chung("All");
			break;
		}
		case 5: {
			break;
		}
		}
	} while (selection2 != 5);
}

void Menu::NhapXuatThongTin() {
	readSettingInfo();
	do {
		string reMa = "[1-3]{1}";
		cout << "---SELECT MENU---" << endl;
		cout << "1. Input setting information" << endl;
		cout << "2. Print setting information" << endl;
		cout << "3. Exit" << endl;
		cout << "Your selection: ";
		selection1 = checkInputInt(reMa);
		system("cls");
		switch (selection1) {
		case 1: {
			NhapThongTinCaiDat();
			break;
		}
		case 2: {
			XuatThongTinCaiDat();
			break;
		}
		case 3: {
			break;
		}
		}
	} while (selection1 != 3);
}