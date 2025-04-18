#include "TextGameBuilder.h"

std::shared_ptr<TextGameEngine> TextGameBuilder::buildTextGame(GameTypeEnum gametype)
{
    return std::make_shared<TextGameEngine>(gametype);
}