#ifndef SOUND_H
#define SOUND_H

#include "IInfo.h"

class Sound : public IInfo
{
public:
    Sound();
    ~Sound();

    virtual std::string getAttribute(int index);
    virtual std::string getAttributeName(int index);
    virtual void setAttribute(int index, std::string newValue);
    virtual int attributeCount();
    virtual void enterAttribute();
    virtual void printAttribute();

    int getMediaLevel() const;
    void setMediaLevel(int newMediaLevel);

    int getCallLevel() const;
    void setCallLevel(int newCallLevel);

    int getNaviLevel() const;
    void setNaviLevel(int newNaviLevel);

    int getNotiLevel() const;
    void setNotiLevel(int newNotiLevel);

private:
    int m_mediaLevel;
    int m_callLevel;
    int m_naviLevel;
    int m_notiLevel;

    int m_attributeCount;
};

#endif // SOUND_H