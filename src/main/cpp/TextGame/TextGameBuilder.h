#ifndef TEXTGAMEBUILDER_H_
#define TEXTGAME_BUILDER_H_

#include <memory>
#include <string>
#include "TextGameEngine.h"

class TextGameBuilder
{
public:
    static std::shared_ptr<TextGameEngine> buildTextGame(std::string game_name);
};

#endif