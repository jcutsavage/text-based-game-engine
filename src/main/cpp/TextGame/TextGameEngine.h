#pragma once

#include <atomic>

#include "GameTypeEnum.h"

class TextGameEngine
{
public:

    TextGameEngine(GameTypeEnum gametype);

    void start();

    void stop();

private:

    void printGametypeSplashScreen();

    GameTypeEnum gametype;
    std::atomic<bool> running;
};