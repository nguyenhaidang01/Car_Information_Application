#include "Common.h"

Common::Common() : m_carName{"unknow"},
                   m_key{"00000000"},
                   m_email{"unknow"},
                   m_odo{0},
                   m_serviceRemind{0},
                   m_attributeCount{5}
{
}

Common::Common(std::string carName, std::string key, std::string email, int odo, int serviceRemind)
    : m_carName{carName},
      m_key{key},
      m_email{email},
      m_odo{odo},
      m_serviceRemind{serviceRemind},
      m_attributeCount{5}
{
}

Common::~Common() {}

std::string Common::getAttribute(int index)
{
    if (index < 0 || index > m_attributeCount - 1)
        return std::string();
    switch (index)
    {
    case 0:
        return getCarName();
    case 1:
        return getKey();
    case 2:
        return getEmail();
    case 3:
        return std::to_string(getOdo());
    default:
        return std::to_string(getServiceRemind());
    }
}
std::string Common::getAttributeName(int index)
{
    if (index < 0 || index > m_attributeCount - 1)
        return std::string();
    switch (index)
    {
    case 0:
        return "carName";
    case 1:
        return "key";
    case 2:
        return "email";
    case 3:
        return "odo";
    default:
        return "serviceRemind";
    }
}
void Common::setAttribute(int index, std::string newValue)
{
    if (index < 0 || index > m_attributeCount - 1)
        return;
    switch (index)
    {
    case 0:
        setCarName(newValue);
        break;
    case 1:
        setKey(newValue);
        break;
    case 2:
        setEmail(newValue);
        break;
    case 3:
        setOdo(std::stoi(newValue));
        break;
    default:
        setServiceRemind(std::stoi(newValue));
        break;
    }
}

int Common::attributeCount()
{
    return m_attributeCount;
}

void Common::enterAttribute()
{
    std::cout << Util::longSpace << "Owner name: ";
    m_carName = Util::validateInput(Util::patternName);
    std::cout << Util::longSpace << "Key number: ";
    m_key = Util::validateInput(Util::patternKey);
    std::cout << Util::longSpace << "Email: ";
    m_email = Util::validateInput(Util::patternEmail);
    std::cout << Util::longSpace << "ODO number: ";
    m_odo = stoi(Util::validateInput(Util::patternOdoAndService));
    std::cout << Util::longSpace << "Remind service: ";
    m_serviceRemind = stoi(Util::validateInput(Util::patternOdoAndService));
}

void Common::printAttribute()
{
    std::cout << std::left << std::setw(25) << "Owner Name" << std::left << std::setw(20) << "Email";
    std::cout << std::left << std::setw(13) << "Key number" << std::left << std::setw(13) << "ODO number";
    std::cout << std::left << std::setw(19) << "Remind service (km)" << std::endl;
    std::cout << std::left << std::setw(3) << "";
    std::cout << std::left << std::setw(25) << m_carName << std::left << std::setw(20) << m_email;
    std::cout << std::left << std::setw(13) << m_key << std::left << std::setw(13) << m_odo;
    std::cout << std::left << std::setw(19) << m_serviceRemind << std::endl;
}

std::string Common::getCarName() const
{
    return m_carName;
}

void Common::setCarName(std::string newCarName)
{
    m_carName = newCarName;
}

std::string Common::getKey() const
{
    return m_key;
}

void Common::setKey(std::string newKey)
{
    m_key = newKey;
}

std::string Common::getEmail() const
{
    return m_email;
}

void Common::setEmail(std::string newEmail)
{
    m_email = newEmail;
}

int Common::getOdo() const
{
    return m_odo;
}

void Common::setOdo(int newOdo)
{
    m_odo = newOdo;
}

int Common::getServiceRemind() const
{
    return m_serviceRemind;
}

void Common::setServiceRemind(int newServiceRemind)
{
    m_serviceRemind = newServiceRemind;
}