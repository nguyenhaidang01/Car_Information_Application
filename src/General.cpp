#include "General.h"

General::General() : m_language{"Vietnamese"},
                     m_timezone{"GMT+07:00"},
                     m_attributeCount{2} {}

General::~General() {}

std::string General::getAttribute(int index)
{
    if (index < 0 || index > m_attributeCount - 1)
        return std::string();
    switch (index)
    {
    case 0:
        return getLanguage();
    default:
        return getTimezone();
    }
}
std::string General::getAttributeName(int index)
{
    if (index < 0 || index > m_attributeCount - 1)
        return std::string();
    switch (index)
    {
    case 0:
        return "Language";
    default:
        return "Timezone";
    }
}
void General::setAttribute(int index, std::string newValue)
{
    if (index < 0 || index > m_attributeCount - 1)
        return;
    switch (index)
    {
    case 0:
        setLanguage(newValue);
        break;
    default:
        setTimezone(newValue);
        break;
    }
}
int General::attributeCount()
{
    return m_attributeCount;
}

void General::enterAttribute()
{
    Util::clearScreen();
    std::vector<std::string> languages = Util::getResource(Util::languagesPath);
    std::sort(languages.begin(), languages.end());
    std::cout << "Enter a number from 1 to 30 corresponding to the language." << std::endl;
    Util::printResource(languages);
    std::cout << Util::longSpace << "Language: ";
    int languageIndex = stoi(Util::validateInput(Util::pattern1_30)) - 1;
    m_language = languages.at(languageIndex);

    Util::clearScreen();
    std::cout << Util::longSpace << "Language: " << m_language << std::endl;
    std::vector<std::string> timezones = Util::getResource(Util::timezonesPath);
    std::cout << "Enter a number from 1 to 32 corresponding to the timezone." << std::endl;
    Util::printResource(timezones);
    std::cout << Util::longSpace << "Timezone: ";
    int timezoneIndex = stoi(Util::validateInput(Util::pattern1_32)) - 1;
    m_timezone = timezones.at(timezoneIndex);
    
    Util::clearScreen();
    std::cout << Util::longSpace << "Language: " << m_language << std::endl;
    std::cout << Util::longSpace << "Timezone: " << m_timezone << std::endl;
}

void General::printAttribute()
{
    std::cout << std::left << std::setw(3) << "" << std::left << std::setw(13) << "General:" << std::left << std::setw(12) << "Timezone";
    std::cout << std::left << std::setw(15) << "Language" << std::endl;
    std::cout << std::left << std::setw(3) << "" << std::left << std::setw(13) << "";
    std::cout << std::left << std::setw(12) << m_timezone << std::left << std::setw(15) << m_language << std::endl;
}

std::string General::getLanguage() const
{
    return m_language;
}

void General::setLanguage(std::string newLanguage)
{
    m_language = newLanguage;
}
std::string General::getTimezone() const
{
    return m_timezone;
}

void General::setTimezone(std::string newTimezone)
{
    m_timezone = newTimezone;
}