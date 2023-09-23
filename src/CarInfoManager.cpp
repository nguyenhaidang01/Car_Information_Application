#include "CarInfoManager.h"

CarInfoManager::CarInfoManager()
    : m_cars{std::make_shared<std::vector<std::shared_ptr<Setting>>>()}
{
}
CarInfoManager::~CarInfoManager()
{
}

int CarInfoManager::validateExistCar(std::shared_ptr<Setting> inputCar)
{
    for (int i = 0; i < m_cars.get()->size(); i++)
    {
        std::string key = m_cars.get()->at(i)->getCommon()->getAttribute(Util::keyIndex);
        std::string inputKey = inputCar.get()->getCommon()->getAttribute(Util::keyIndex);
        if (inputKey == key)
            return i;
    }
    return -1;
}

void CarInfoManager::enterAndPrintCarInfo()
{
    readSettingsFromDatabase();
    int selection;
    while (true)
    {
        Util::clearScreen();
        std::cout << "--- SELECT MENU ---" << std::endl;
        std::cout << "1. Input setting information" << std::endl;
        std::cout << "2. Print setting information" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Your selection: ";
        selection = stoi(Util::validateInput(Util::pattern1_3));
        Util::clearScreen();
        switch (selection)
        {
        case 1:
            enterCarInfo();
            break;
        case 2:
            printCarInfo();
            break;
        default:
            return;
        }
    }
}

void CarInfoManager::enterCarInfo()
{
    int selection;
    while (true)
    {
        Util::clearScreen();
        std::cout << "--- SELECT MENU ---" << std::endl;
        std::cout << "1. Display setting" << std::endl;
        std::cout << "2. Sound setting" << std::endl;
        std::cout << "3. General setting" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Your selection: ";
        selection = stoi(Util::validateInput(Util::pattern0_3));
        Util::clearScreen();
        switch (selection)
        {
        case 1:
            enterCarInfoByType(Util::DisplayInfo);
            break;
        case 2:
            enterCarInfoByType(Util::SoundInfo);
            break;
        case 3:
            enterCarInfoByType(Util::GeneralInfo);
            break;
        default:
            return;
        }
    }
}

void CarInfoManager::printCarInfo()
{
    int selection;
    while (true)
    {
        Util::clearScreen();
        std::cout << "--- SELECT MENU ---" << std::endl;
        std::cout << "1. Print Display setting information" << std::endl;
        std::cout << "2. Print Sound setting information" << std::endl;
        std::cout << "3. Print General setting information" << std::endl;
        std::cout << "4. Print all setting information" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Your selection: ";
        selection = stoi(Util::validateInput(Util::pattern1_5));
        Util::clearScreen();
        switch (selection)
        {
        case 1:
            printCarInfoByType(Util::DisplayInfo);
            break;
        case 2:
            printCarInfoByType(Util::SoundInfo);
            break;
        case 3:
            printCarInfoByType(Util::GeneralInfo);
            break;
        case 4:
            printCarInfoByType(Util::AllInfo);
            break;
        default:
            return;
        }
    }
}

void CarInfoManager::enterCarInfoByType(int infoType)
{
    Util::clearScreen();
    std::shared_ptr<Setting> inputCar = std::make_shared<Setting>();

    std::cout << "Car index: " << m_cars.get()->size() << std::endl;
    inputCar.get()->getCommon()->enterAttribute();
    std::cout << "--------------------------------" << std::endl;

    std::shared_ptr<IInfo> inputTypeInfo;
    switch (infoType)
    {
    case Util::DisplayInfo:
        inputTypeInfo = inputCar.get()->getDisplay();
        break;
    case Util::SoundInfo:
        inputTypeInfo = inputCar.get()->getSound();
        break;
    default:
        inputTypeInfo = inputCar.get()->getGeneral();
        break;
    }

    inputTypeInfo.get()->enterAttribute();

    int existIndex = validateExistCar(inputCar);
    if (existIndex == Util::indexNotFound)
    {
        std::cout << "-> This is car, data will be appended to your list." << std::endl;
        m_cars.get()->push_back(inputCar);
    }
    else
    {
        std::cout << "-> This car already existed, data will be overridden." << std::endl;
        m_cars.get()->at(existIndex) = inputCar;
    }
    writeSettingsToDatabase();
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Will you input for car " << m_cars.get()->size() << " (y/n)?: ";
    std::string inputChoice = Util::validateInput(Util::patternY_n);
    if (inputChoice == "y")
        enterCarInfoByType(infoType);
}

void CarInfoManager::printCarInfoByType(int infoType)
{
    Util::clearScreen();
    int carsCount = m_cars.get()->size();
    std::cout << "--- Setting Information --- " << std::endl;
    if (carsCount == 0)
    {
        std::cout << "Setting Information is Empty!" << std::endl;
        Util::pauseScreen();
    }
    else
    {
        for (int i = 0; i < carsCount; i++)
        {
            std::cout << std::left << std::setw(3) << i;
            m_cars.get()->at(i).get()->getCommon().get()->printAttribute();
            switch (infoType)
            {
            case Util::DisplayInfo:
                m_cars.get()->at(i).get()->getDisplay().get()->printAttribute();
                break;
            case Util::SoundInfo:
                m_cars.get()->at(i).get()->getSound().get()->printAttribute();
                break;
            case Util::GeneralInfo:
                m_cars.get()->at(i).get()->getGeneral().get()->printAttribute();
                break;
            default:
                m_cars.get()->at(i).get()->getDisplay().get()->printAttribute();
                m_cars.get()->at(i).get()->getSound().get()->printAttribute();
                m_cars.get()->at(i).get()->getGeneral().get()->printAttribute();
                break;
            }
        }
        Util::pauseScreen();
    }
}

void CarInfoManager::writeSettingsToDatabase()
{
    if (!Util::validateDatabaseExist())
    {
        if (Util::createDatabase())
        {
            std::cout << "Database created successfully." << std::endl;
        }
        else
        {
            std::cerr << "Failed to create database." << std::endl;
            return;
        }
    }

    sqlite3 *database;
    const char *databasePath = "Settings.db";
    if (!sqlite3_open(databasePath, &database) == SQLITE_OK)
    {
        std::cerr << "Unable to open the database for writing!" << std::endl;
        return;
    }

    const char *query = "INSERT INTO settings (name, key, email, odo, remindService, displayLight, screenLight, taploLight, media, call, navi, noti, language, timezone) "
                        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(database, query, -1, &stmt, 0) == SQLITE_OK)
    {
        for (const auto &car : *m_cars)
        {
            std::string carName, key, email;
            int odo, remindService;
            int lightLevel, screenLightLevel, taploLightLevel;
            int mediaLevel, callLevel, naviLevel, notiLevel;
            std::string language, timezone;

            carName = car.get()->getCommon().get()->getAttribute(Util::nameIndex);
            key = car.get()->getCommon().get()->getAttribute(Util::keyIndex);
            email = car.get()->getCommon().get()->getAttribute(Util::emailIndex);
            odo = std::stoi(car.get()->getCommon().get()->getAttribute(Util::odoIndex));
            remindService = std::stoi(car.get()->getCommon().get()->getAttribute(Util::serviceRemindIndex));

            lightLevel = std::stoi(car.get()->getDisplay().get()->getAttribute(Util::lightLevelIndex));
            screenLightLevel = std::stoi(car.get()->getDisplay().get()->getAttribute(Util::screenLightLevelIndex));
            taploLightLevel = std::stoi(car.get()->getDisplay().get()->getAttribute(Util::taploLightLevelIndex));

            mediaLevel = std::stoi(car.get()->getSound().get()->getAttribute(Util::mediaLevelIndex));
            callLevel = std::stoi(car.get()->getSound().get()->getAttribute(Util::callLevelIndex));
            naviLevel = std::stoi(car.get()->getSound().get()->getAttribute(Util::naviLevelIndex));
            notiLevel = std::stoi(car.get()->getSound().get()->getAttribute(Util::notiLevelIndex));

            language = car.get()->getSound().get()->getAttribute(Util::languageIndex);
            timezone = car.get()->getSound().get()->getAttribute(Util::timezoneIndex);

            sqlite3_bind_text(stmt, 1, carName.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, key.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 4, odo);
            sqlite3_bind_int(stmt, 5, remindService);
            sqlite3_bind_int(stmt, 6, lightLevel);
            sqlite3_bind_int(stmt, 7, screenLightLevel);
            sqlite3_bind_int(stmt, 8, taploLightLevel);
            sqlite3_bind_int(stmt, 9, mediaLevel);
            sqlite3_bind_int(stmt, 10, callLevel);
            sqlite3_bind_int(stmt, 11, naviLevel);
            sqlite3_bind_int(stmt, 12, notiLevel);
            sqlite3_bind_text(stmt, 13, language.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 14, timezone.c_str(), -1, SQLITE_STATIC);
            if (sqlite3_step(stmt) != SQLITE_DONE)
            {
                sqlite3_finalize(stmt);
                sqlite3_close(database);
                std::cerr << "Write failure!" << std::endl;
                return;
            }
            sqlite3_reset(stmt);
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(database);
}

void CarInfoManager::readSettingsFromDatabase()
{
    if (!Util::validateDatabaseExist())
        return;

    sqlite3 *database;
    const char *databasePath = "Settings.db";
    if (!sqlite3_open(databasePath, &database) == SQLITE_OK)
    {
        std::cerr << "Unable to open the database for reading!" << std::endl;
        return;
    }

    const char *query = "SELECT * FROM settings";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(database, query, -1, &stmt, 0) == SQLITE_OK)
    {
        m_cars.get()->clear();
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            std::shared_ptr<Setting> car = std::make_shared<Setting>();

            std::string carName, key, email;
            int odo, remindService;
            int lightLevel, screenLightLevel, taploLightLevel;
            int mediaLevel, callLevel, naviLevel, notiLevel;
            std::string language, timezone;

            carName = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
            key = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
            email = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
            odo = sqlite3_column_int(stmt, 3);
            remindService = sqlite3_column_int(stmt, 4);
            lightLevel = sqlite3_column_int(stmt, 5);
            screenLightLevel = sqlite3_column_int(stmt, 6);
            taploLightLevel = sqlite3_column_int(stmt, 7);
            mediaLevel = sqlite3_column_int(stmt, 8);
            callLevel = sqlite3_column_int(stmt, 9);
            naviLevel = sqlite3_column_int(stmt, 10);
            notiLevel = sqlite3_column_int(stmt, 11);
            language = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 12)));
            timezone = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 13)));

            car.get()->getCommon().get()->setAttribute(Util::nameIndex, carName);
            car.get()->getCommon().get()->setAttribute(Util::keyIndex, key);
            car.get()->getCommon().get()->setAttribute(Util::emailIndex, email);
            car.get()->getCommon().get()->setAttribute(Util::odoIndex, std::to_string(odo));
            car.get()->getCommon().get()->setAttribute(Util::serviceRemindIndex, std::to_string(remindService));

            car.get()->getDisplay().get()->setAttribute(Util::lightLevelIndex, std::to_string(lightLevel));
            car.get()->getDisplay().get()->setAttribute(Util::screenLightLevelIndex, std::to_string(screenLightLevel));
            car.get()->getDisplay().get()->setAttribute(Util::taploLightLevelIndex, std::to_string(taploLightLevel));

            car.get()->getSound().get()->setAttribute(Util::mediaLevelIndex, std::to_string(mediaLevel));
            car.get()->getSound().get()->setAttribute(Util::callLevelIndex, std::to_string(callLevel));
            car.get()->getSound().get()->setAttribute(Util::naviLevelIndex, std::to_string(naviLevel));
            car.get()->getSound().get()->setAttribute(Util::notiLevelIndex, std::to_string(notiLevel));

            car.get()->getGeneral().get()->setAttribute(Util::languageIndex, language);
            car.get()->getGeneral().get()->setAttribute(Util::timezoneIndex, timezone);

            m_cars.get()->push_back(car);
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(database);
}