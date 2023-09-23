#ifndef SETTING_H
#define SETTING_H

#include "Common.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"
#include <memory>

class Setting
{
public:
    Setting();
    ~Setting();

    std::shared_ptr<IInfo> getCommon() const;
    void setCommon(std::shared_ptr<IInfo> common);

    std::shared_ptr<IInfo> getDisplay() const;
    void setDisplay(std::shared_ptr<IInfo> display);

    std::shared_ptr<IInfo> getSound() const;
    void setSound(std::shared_ptr<IInfo> sound);

    std::shared_ptr<IInfo> getGeneral() const;
    void setGeneral(std::shared_ptr<IInfo> general);

private:
    std::shared_ptr<IInfo> m_common;
    std::shared_ptr<IInfo> m_display;
    std::shared_ptr<IInfo> m_sound;
    std::shared_ptr<IInfo> m_general;
};

#endif // SETTING_H