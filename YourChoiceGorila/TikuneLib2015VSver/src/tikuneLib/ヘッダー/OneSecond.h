#pragma once

#include "Common.h"

class OneSecondCount
{
public:
    OneSecondCount(){}
    ~OneSecondCount(){}

    int  time = 0;
    bool isElapsed = false;

    void OneSecond();
};