#pragma once

#include <iostream>
#include <windows.h>
#include <ctime>

class TimeInterval
{
    private:

        unsigned int initTime;

    public:

        inline TimeInterval() : initTime(GetTickCount())
        {}

        inline unsigned int value() const
        {
            return (GetTickCount() - initTime);
        }

        virtual ~TimeInterval()
        {}
};

class TimeUtil
{
    public:

        static void delay(float sec)
        {
            unsigned int delayTime = (unsigned int)(sec * 1000);
            for(TimeInterval clk; clk.value() < delayTime;);
        }
};
