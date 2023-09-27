#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <regex>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <algorithm>
#include "sqlite3.h"

namespace Util
{
    void clearScreen();
    void pauseScreen();
    std::string validateInput(const std::string &regexPattern);

    bool validateDatabaseExist();
    bool createDatabase();

    std::vector<std::string> getResource(const std::string &filePath);
    void printResource(const std::vector<std::string> &resource);

    // Type Info
    const int DisplayInfo = 0;
    const int SoundInfo = 1;
    const int GeneralInfo = 2;
    const int AllInfo = 3;

    // Common Attribute Index
    const int nameIndex = 0;
    const int keyIndex = 1;
    const int emailIndex = 2;
    const int odoIndex = 3;
    const int serviceRemindIndex = 4;

    // Display Attribute Index
    const int lightLevelIndex = 0;
    const int screenLightLevelIndex = 1;
    const int taploLightLevelIndex = 2;

    // Sound Attribute Index
    const int mediaLevelIndex = 0;
    const int callLevelIndex = 1;
    const int naviLevelIndex = 2;
    const int notiLevelIndex = 3;

    // General Attribute Index
    const int languageIndex = 0;
    const int timezoneIndex = 1;

    const int indexNotFound = -1;
    const std::string longSpace = "   ";
    const std::string languagesPath = "languages.txt";
    const std::string timezonesPath = "timezones.txt";

    // Regex pattern
    const std::string patternY_n = "[yn]{1}";
    const std::string pattern0_3 = "[0-3]{1}";
    const std::string pattern1_3 = "[1-3]{1}";
    const std::string pattern1_5 = "[1-5]{1}";
    const std::string pattern1_30 = "^(30|[1-9]|[1-2][0-9])$";
    const std::string pattern1_32 = "^(3[0-2]|[1-2]?[0-9])$";
    const std::string patternName = "^[A-Za-z]+( [A-Za-z]+)*$";
    const std::string patternEmail = "[A-Za-z0-9_]{2,}\.@[A-Za-z]{2,}\.([A-Za-z]{3})";
    const std::string patternKey = "[0-9]{8}";
    const std::string patternOdoAndService = "[0-9]+";
    const std::string patternSettingLevel = "(10|[0-9]){1}";

}

#endif // UTIL_H
