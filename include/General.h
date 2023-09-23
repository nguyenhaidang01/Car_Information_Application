#ifndef GENERAL_H
#define GENERAL_H

#include "IInfo.h"

class General : public IInfo
{
public:
    General();
    ~General();

    virtual std::string getAttribute(int index);
    virtual std::string getAttributeName(int index);
    virtual void setAttribute(int index, std::string newValue);
    virtual int attributeCount();
    virtual void enterAttribute();
    virtual void printAttribute();

    std::string getLanguage() const;
    void setLanguage(std::string newLanguage);

    std::string getTimezone() const;
    void setTimezone(std::string newTimezone);

private:
    std::string m_language;
    std::string m_timezone;

    int m_attributeCount;
};

#endif // GENERAL_H