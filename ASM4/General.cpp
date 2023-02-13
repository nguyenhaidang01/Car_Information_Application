#include "General.h"

General::General() : Common() {
	timezone = "(GMT+07:00)";
	language = "Vietnamese";
}

General::~General() {

}

void General::showTimeList() {
	string temp;
	int i = 1;
	ifstream inputFile("timezones.txt");
	if (inputFile.is_open()) {
		while (!inputFile.eof()) {
			getline(inputFile, temp);
			if (i < 10) {
				cout << " " << i << ". " << temp << endl;
			}
			else {
				cout << i << ". " << temp << endl;
			}
			i++;
		}
	}
}

void General::showLangList(vector<string>& ltList) {
	for (int i = 0; i < ltList.size(); i++) {
		if (i < 9) {
			cout << " " << i + 1 << "/ " << ltList[i] << endl;
		}
		else {
			cout << i + 1 << "/ " << ltList[i] << endl;
		}
	}
}

//Lưu dữ liệu từ 2 file languages và timezones
void General::downloadLTList(vector<string>& ltList, string fileName) {
	General* check = new General();
	check->checkFileLT("timezones.txt");
	check->checkFileLT("languages.txt");
	ifstream inputFile(fileName);
	try {
		if (inputFile.is_open()) {
			while (!inputFile.eof()) {
				char temp[255];
				inputFile.getline(temp, 255);
				char* shorter;
				if (fileName == "timezones.txt") {
					shorter = strtok(temp, " ");
					ltList.push_back(shorter);
				}
				if (fileName == "languages.txt") {
					shorter = strtok(temp, "/");
					shorter = strtok(NULL, " ");
					ltList.push_back(shorter);
				}
			}
		}
		else {
			throw exception();
		}
	}
	catch (...) {
		cerr << "ERROR TO READ FILE!" << endl;
	}

	//Sử dụng thư viện STL để sắp xếp
	if ((fileName == "languages.txt") && inputFile.is_open()) {
		sort(ltList.begin(), ltList.end());
	}
	inputFile.close();
}

void General::nhapThongTin() {
	vector<string> timeList;
	vector<string> langList;
	downloadLTList(timeList, "timezones.txt");
	downloadLTList(langList, "languages.txt");

	int selectLanguage, selectTimeZone;

	string settingLang = "[1-9]|1[0-9]|2[0-9]|30";
	string settingTime = "[1-9]|1[0-9]|2[0-9]|3[0-2]";

	system("cls");
	cout << setw(45) << "Timezone: Select one Timezone in the List!" << endl;
	showTimeList();
	cout << setw(19) << "Your selection: ";
	selectTimeZone = checkInputInt(settingTime);
	system("cls");
	cout << setw(13) << "Timezone: " << timeList[selectTimeZone - 1] << endl;

	cout << setw(45) << "Language: Select one Language in the List!" << endl;
	showLangList(langList);
	cout << setw(19) << "Your selection: ";
	selectLanguage = checkInputInt(settingLang);

	setTimezone(timeList[selectTimeZone - 1]);
	setLanguage(langList[selectLanguage - 1]);
}

void General::xuatThongTin() {
	cout << setw(13) << "Timezone: " << getTimezone() << endl;
	cout << setw(13) << "Language: " << getLanguage() << endl;
}

string General::getLanguage() {
	return language;
}

string General::getTimezone() {
	return timezone;
}

void General::setLanguage(string data) {
	language = data;
}

void General::setTimezone(string data) {
	timezone = data;
}

//Tạo hoặc viết lại file timezone
void General::writeFileTime() {
	ofstream outputFile("timezones.txt");
	try {
		if (outputFile.is_open()) {
			outputFile << "(GMT-12:00) / International Date Line West" << endl << "(GMT-11:00) / Midway Island, Samoa" << endl
				<< "(GMT-10:00) / Hawaii" << endl << "(GMT-09:00) / Alaska" << endl << "(GMT-08:00) / Tijuana, Baja California" << endl
				<< "(GMT-07:00) / Chihuahua, La Paz, Mazatlan - New" << endl << "(GMT-06:00) / Guadalajara, Mexico City, Monterrey - New" << endl
				<< "(GMT-05:00) / Eastern Time(US and Canada)" << endl << "(GMT-04:00) / Atlantic Time(Canada)" << endl
				<< "(GMT-03:30) / Newfoundland" << endl << "(GMT-02:00) / Mid - Atlantic" << endl << "(GMT-01:00) / Azores" << endl
				<< "(GMT-00:00) / Monrovia, Reykjavik" << endl << "(GMT+01:00) / Belgrade, Bratislava, Budapest, Ljubljana, Prague" << endl
				<< "(GMT+02:00) / Minsk" << endl << "(GMT+03:00) / Moscow, St.Petersburg, Volgograd" << endl
				<< "(GMT+04:00) / Abu Dhabi, Muscat" << endl << "(GMT+04:30) / Kabul" << endl << "(GMT+05:00) / Tashkent" << endl
				<< "(GMT+05:30) / Chennai, Kolkata, Mumbai, New Delhi" << endl << "(GMT+05:45) / Kathmandu" << endl
				<< "(GMT+06:00) / Astana, Dhaka" << endl << "(GMT+06:30) / Yangon(Rangoon) /" << endl
				<< "(GMT+07:00) / Bangkok, Hanoi, Jakarta" << endl << "(GMT+08:00) / Beijing, Chongqing, Hong Kong, Urumqi" << endl
				<< "(GMT+08:00) / Irkutsk, Ulaanbaatar" << endl << "(GMT+09:00) / Seoul" << endl << "(GMT+09:30) / Adelaide" << endl
				<< "(GMT+10:00) / Canberra, Melbourne, Sydney" << endl << "(GMT+11:00) / Magadan, Solomon Islands, New Caledonia" << endl
				<< "(GMT+12:00) / Fiji, Kamchatka, Marshall Is." << endl << "(GMT+13:00) / Nuku'alofa";
			outputFile.close();
		}
		else {
			throw 208;
		}
	}
	catch (int) {
		cerr << "Can not write file timezones.txt" << endl;
	}
	catch (...) {
		cerr << "ERROR TO WRITE!" << endl;
	}
}

//Tạo hoặc viết lại file language
void General::writeFileLanguage() {
	ofstream fileText("languages.txt");
	try {
		if (fileText.is_open()) {
			fileText << "1 / Mandarin (entire branch)" << endl << "2 / Spanish" << endl << "3 / English" << endl <<
				"4 / Hindi" << endl << "5 / Arabic" << endl << "6 / Portuguese" << endl <<
				"7 / Bengali" << endl << "8 / Russian" << endl << "9 / Japanese" << endl << "10 / Punjabi" << endl <<
				"11 / German" << endl << "12 / Javanese" << endl << "13 / Wu (inc.Shanghainese)" << endl <<
				"14 / Malay (inc.Indonesian and Malaysian)" << endl << "15 / Telugu" << endl << "16 / Vietnamese" << endl <<
				"17 / Korean" << endl << "18 / French" << endl << "19 / Marathi" << endl <<
				"20 / Tamil" << endl << "21 / Urdu" << endl << "22 / Turkish" << endl <<
				"23 / Italian" << endl << "24 / Yue (inc.Cantonese)" << endl << "25 / Thai" << endl <<
				"26 / Gujarati" << endl << "27 / Jin" << endl << "28 / Southern Min" << endl <<
				"29 / Persian" << endl << "30 / Polish";
			fileText.close();
		}
		else {
			throw 208;
		}
	}
	catch (int) {
		cerr << "Can not Write File languages.txt " << endl;
	}
	catch (...) {
		cout << "ERROR TO WRITE!" << endl;
	}
}

// kiểm soát ngoại lệ 2 file timezone, language
void General::checkFileLT(string fileName) {
	ifstream inputFile(fileName);
	try {
		if (inputFile.fail()) {
			throw 208;
		}
		else if (checkEmptyFile(inputFile)) {
			if (fileName == "timezones.txt") {
				throw "timezones.txt is Emty. Dowload data...";
			}
			if (fileName == "languages.txt") {
				throw "languages.txt is Emty. Dowload data...";
			}	
		}
	}
	catch (int) {		
		if (fileName == "timezones.txt") {
			cerr << "File timezone.txt is not Exits! Create new File..." << endl;
			writeFileTime();
		}
		if (fileName == "languages.txt") {
			cerr << "File languages.txt is not Exits! Create new File..." << endl;
			writeFileLanguage();
		}		
	}
	catch (const char* msg) {
		cerr << msg << endl << endl;
		if (fileName == "timezones.txt") {
			writeFileTime();
		}
		if (fileName == "languages.txt") {
			writeFileLanguage();
		}
	}
	catch (...) {
		cerr << "ERROR!" << endl;
		if (fileName == "timezones.txt") {
			writeFileTime();
		}
		if (fileName == "languages.txt") {
			writeFileLanguage();
		}
	}
}