#pragma once

#include <memory>
#include <string>
#include "TextGameEngine.h"
#include "GameTypeEnum.h"

class TextGameBuilder
{
public:
    static std::shared_ptr<TextGameEngine> buildTextGame(GameTypeEnum gametype);
};