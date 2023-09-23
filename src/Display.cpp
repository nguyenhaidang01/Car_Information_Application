#include "Display.h"

Display::Display() : m_lightLevel{0},
                     m_screenLightLevel{0},
                     m_taploLightLevel{0},
                     m_attributeCount{3} {};

Display::~Display(){};

std::string Display::getAttribute(int index)
{
    if (index < 0 || index > m_attributeCount - 1)
        return std::string();
    switch (index)
    {
    case 0:
        return std::to_string(getLightLevel());
    case 1:
        return std::to_string(getScreenLightLevel());
    default:
        return std::to_string(getTaploLightLevel());
    }
}
std::string Display::getAttributeName(int index)
{
    if (index < 0 || index > m_attributeCount - 1)
        return std::string();
    switch (index)
    {
    case 0:
        return "Light level";
    case 1:
        return "Screen light level";
    default:
        return "Taplo light level";
    }
}

void Display::setAttribute(int index, std::string newValue)
{
    if (index < 0 || index > m_attributeCount - 1)
        return;
    switch (index)
    {
    case 0:
        setLightLevel(std::stoi(newValue));
        break;
    case 1:
        setScreenLightLevel(std::stoi(newValue));
        break;
    default:
        setTaploLightLevel(std::stoi(newValue));
        break;
    }
}

int Display::attributeCount()
{
    return m_attributeCount;
}

void Display::enterAttribute()
{
    std::cout << Util::longSpace << "Light level: ";
    m_lightLevel = stoi(Util::validateInput(Util::patternSettingLevel));
    std::cout << Util::longSpace << "Screen light level: ";
    m_screenLightLevel = stoi(Util::validateInput(Util::patternSettingLevel));
    std::cout << Util::longSpace << "Taplo light level: ";
    m_taploLightLevel = stoi(Util::validateInput(Util::patternSettingLevel));
}

void Display::printAttribute()
{
    std::cout << std::left << std::setw(3) << "" << std::left << std::setw(13) << "Display:" << std::left << std::setw(8) << "Light";
    std::cout << std::left << std::setw(15) << "Screen light" << std::left << std::setw(14) << "Taplo light" << std::endl;
    std::cout << std::left << std::setw(3) << "" << std::left << std::setw(13) << "" << std::left << std::setw(8) << m_lightLevel;
    std::cout << std::left << std::setw(15) << m_screenLightLevel << std::left << std::setw(14) << m_taploLightLevel << std::endl;
}

int Display::getLightLevel() const
{
    return m_lightLevel;
}

void Display::setLightLevel(int newLightLevel)
{
    m_lightLevel = newLightLevel;
}
int Display::getScreenLightLevel() const
{
    return m_screenLightLevel;
}

void Display::setScreenLightLevel(int newScreenLightLevel)
{
    m_screenLightLevel = newScreenLightLevel;
}

int Display::getTaploLightLevel() const
{
    return m_taploLightLevel;
}

void Display::setTaploLightLevel(int newTaploLightLevel)
{
    m_taploLightLevel = newTaploLightLevel;
}