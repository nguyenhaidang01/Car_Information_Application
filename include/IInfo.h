#ifndef IINFO_H
#define IINFO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Util.h"

class IInfo
{
public:
    virtual std::string getAttribute(int index) = 0;
    virtual std::string getAttributeName(int index) = 0;
    virtual void setAttribute(int index, std::string newValue) = 0;
    virtual int attributeCount() = 0;
    virtual void enterAttribute() = 0;
    virtual void printAttribute() = 0;
};

#endif // IINFO_H