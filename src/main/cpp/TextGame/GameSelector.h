#pragma once

#include <vector>
#include <string>

#include "GameTypeEnum.h"

class GameSelector
{
public:
    GameSelector();

    GameTypeEnum selectGame();

private:
    std::vector<std::vector<std::string>> gametypes;
};