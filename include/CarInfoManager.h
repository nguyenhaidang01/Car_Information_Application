#ifndef CARINFOMANAGER_H
#define CARINFOMANAGER_H

#include "Setting.h"
#include "Util.h"
#include <vector>
#include <fstream>

class CarInfoManager
{
public:
    CarInfoManager();
    ~CarInfoManager();

    void enterAndPrintCarInfo();

private:
    void enterCarInfo();
    void printCarInfo();

    void enterCarInfoByType(int infoType);
    void printCarInfoByType(int infoType);

    void writeSettingsToDatabase();
    void readSettingsFromDatabase();

    int validateExistCar(std::shared_ptr<Setting> inputCar);
    std::shared_ptr<std::vector<std::shared_ptr<Setting>>> m_cars;
};

#endif // CARINFOMANAGER_H