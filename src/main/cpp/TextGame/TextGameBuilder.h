#ifndef TEXTGAMEBUILDER_H_
#define TEXTGAME_BUILDER_H_

#include <memory>
#include "TextGame.h"

class TextGameBuilder
{
public:
    static std::shared_ptr<TextGame> buildTextGame();
};

#endif