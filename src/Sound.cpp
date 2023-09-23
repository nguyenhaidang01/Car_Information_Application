#include "Sound.h"

Sound::Sound() : m_mediaLevel{0},
                 m_callLevel{0},
                 m_naviLevel{0},
                 m_notiLevel{0},
                 m_attributeCount{4}
{
}

Sound::~Sound() {}

std::string Sound::getAttribute(int index)
{
    if (index < 0 || index > m_attributeCount - 1)
        return std::string();
    switch (index)
    {
    case 0:
        return std::to_string(getMediaLevel());
    case 1:
        return std::to_string(getCallLevel());
    case 2:
        return std::to_string(getNaviLevel());
    default:
        return std::to_string(getNotiLevel());
    }
}
std::string Sound::getAttributeName(int index)
{
    if (index < 0 || index > m_attributeCount - 1)
        return std::string();
    switch (index)
    {
    case 0:
        return "Media level";
    case 1:
        return "Call level";
    case 2:
        return "Navi level";
    default:
        return "Noti level";
    }
}
void Sound::setAttribute(int index, std::string newValue)
{
    if (index < 0 || index > m_attributeCount - 1)
        return;
    switch (index)
    {
    case 0:
        setMediaLevel(std::stoi(newValue));
        break;
    case 1:
        setCallLevel(std::stoi(newValue));
        break;
    case 2:
        setNaviLevel(std::stoi(newValue));
        break;
    default:
        setNotiLevel(std::stoi(newValue));
        break;
    }
}
int Sound::attributeCount()
{
    return m_attributeCount;
}

void Sound::enterAttribute()
{
    std::cout << Util::longSpace << "Media level: ";
    m_mediaLevel = stoi(Util::validateInput(Util::patternSettingLevel));
    std::cout << Util::longSpace << "Call level: ";
    m_callLevel = stoi(Util::validateInput(Util::patternSettingLevel));
    std::cout << Util::longSpace << "Navi level: ";
    m_naviLevel = stoi(Util::validateInput(Util::patternSettingLevel));
    std::cout << Util::longSpace << "Noti level: ";
    m_notiLevel = stoi(Util::validateInput(Util::patternSettingLevel));
}

void Sound::printAttribute()
{
    std::cout << std::left << std::setw(3) << "" << std::left << std::setw(13) << "Sound:" << std::left << std::setw(8) << "Media";
    std::cout << std::left << std::setw(8) << "Call" << std::left << std::setw(13) << "Navigation";
    std::cout << std::left << std::setw(15) << "Notification" << std::endl;
    std::cout << std::left << std::setw(3) << "" << std::left << std::setw(13) << "";
    std::cout << std::left << std::setw(8) << m_mediaLevel << std::left << std::setw(8) << m_callLevel;
    std::cout << std::left << std::setw(13) << m_naviLevel << std::left << std::setw(15) << m_notiLevel << std::endl;
}

int Sound::getMediaLevel() const
{
    return m_mediaLevel;
}

void Sound::setMediaLevel(int newMediaLevel)
{
    m_mediaLevel = newMediaLevel;
}

int Sound::getCallLevel() const
{
    return m_callLevel;
}

void Sound::setCallLevel(int newCallLevel)
{
    m_callLevel = newCallLevel;
}

int Sound::getNaviLevel() const
{
    return m_naviLevel;
}

void Sound::setNaviLevel(int newNaviLevel)
{
    m_naviLevel = newNaviLevel;
}

int Sound::getNotiLevel() const
{
    return m_notiLevel;
}

void Sound::setNotiLevel(int newNotiLevel)
{
    m_notiLevel = newNotiLevel;
}