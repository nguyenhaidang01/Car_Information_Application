#ifndef DISPLAY_H
#define DISPLAY_H

#include "IInfo.h"

class Display : public IInfo
{
public:
    Display();
    ~Display();

    virtual std::string getAttribute(int index);
    virtual std::string getAttributeName(int index);
    virtual void setAttribute(int index, std::string newValue);
    virtual int attributeCount();
    virtual void enterAttribute();
    virtual void printAttribute();

    int getLightLevel() const;
    void setLightLevel(int newLightLevel);

    int getScreenLightLevel() const;
    void setScreenLightLevel(int newScreenLightLevel);

    int getTaploLightLevel() const;
    void setTaploLightLevel(int newTaploLightLevel);

private:
    int m_lightLevel;
    int m_screenLightLevel;
    int m_taploLightLevel;

    int m_attributeCount;
};

#endif // DISPLAY_H