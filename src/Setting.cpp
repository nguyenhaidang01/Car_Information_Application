#include "Setting.h"

Setting::Setting() : m_common{std::make_shared<Common>()},
                     m_display{std::make_shared<Display>()},
                     m_sound{std::make_shared<Sound>()},
                     m_general{std::make_shared<General>()}
{
}

Setting::~Setting() {}

std::shared_ptr<IInfo> Setting::getCommon() const
{
    return m_common;
}

void Setting::setCommon(std::shared_ptr<IInfo> newCommon)
{
    m_common = newCommon;
}

std::shared_ptr<IInfo> Setting::getDisplay() const
{
    return m_display;
}

void Setting::setDisplay(std::shared_ptr<IInfo> newDisplay)
{
    m_display = newDisplay;
}

std::shared_ptr<IInfo> Setting::getSound() const
{
    return m_sound;
}

void Setting::setSound(std::shared_ptr<IInfo> newSound)
{
    m_sound = newSound;
}

std::shared_ptr<IInfo> Setting::getGeneral() const
{
    return m_general;
}

void Setting::setGeneral(std::shared_ptr<IInfo> newGeneral)
{
    m_general = newGeneral;
}