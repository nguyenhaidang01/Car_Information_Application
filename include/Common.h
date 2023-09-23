#ifndef COMMON_H
#define COMMON_H

#include "IInfo.h"

class Common : public IInfo
{
public:
    Common();
    Common(std::string m_carName, std::string m_key, std::string m_email, int m_odo, int m_serviceRemind);
    ~Common();

    virtual std::string getAttribute(int index);
    virtual std::string getAttributeName(int index);
    virtual void setAttribute(int index, std::string newValue);
    virtual int attributeCount();
    virtual void enterAttribute();
    virtual void printAttribute();

    std::string getCarName() const;
    void setCarName(std::string newCarName);

    std::string getKey() const;
    void setKey(std::string newKey);

    std::string getEmail() const;
    void setEmail(std::string newEmail);

    int getOdo() const;
    void setOdo(int newOdo);

    int getServiceRemind() const;
    void setServiceRemind(int newServiceRemind);

private:
    std::string m_carName;
    std::string m_key;   // Chuoi 8 ky tu so
    std::string m_email; // email format abc@xyz.com
    int m_odo;
    int m_serviceRemind;

    int m_attributeCount;
};

#endif // COMMON_H